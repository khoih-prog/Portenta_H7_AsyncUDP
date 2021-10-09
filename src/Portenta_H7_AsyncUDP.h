/****************************************************************************************************************************
  Portenta_H7_AsyncUDP.h
  
  For Portenta_H7 (STM32H7) with Vision-Shield Ethernet
  
  Portenta_H7_AsyncWebServer is a library for the Portenta_H7 with with Vision-Shield Ethernet
  
  Based on and modified from AsyncTCP (https://github.com/me-no-dev/ESPAsyncUDP)
  Built by Khoi Hoang https://github.com/khoih-prog/Portenta_H7_AsyncUDP
  
  This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License 
  as published bythe Free Software Foundation, either version 3 of the License, or (at your option) any later version.
  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
  You should have received a copy of the GNU General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>.
 
  Version: 1.0.0
  
  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      09/10/2021 Initial coding for Portenta_H7 (STM32H7) with Vision-Shield Ethernet                     
 *****************************************************************************************************************************/

#pragma once

#ifndef PORTENTA_H7_ASYNC_UDP_H
#define PORTENTA_H7_ASYNC_UDP_H

#if ( defined(ARDUINO_PORTENTA_H7_M7) || defined(ARDUINO_PORTENTA_H7_M4) )

  #if defined(BOARD_NAME)
    #undef BOARD_NAME
  #endif

  #if defined(CORE_CM7)
    //#warning Using Portenta H7 M7 core
    #define BOARD_NAME              "PORTENTA_H7_M7"
  #else
    //#warning Using Portenta H7 M4 core
    #define BOARD_NAME              "PORTENTA_H7_M4"
  #endif

#else

  #error For Portenta_H7 only
    
#endif

#if defined(SHIELD_TYPE)
  #undef SHIELD_TYPE
#endif

#if (ETHERNET_USE_PORTENTA_H7 || USE_ETHERNET_PORTENTA_H7)
  #define SHIELD_TYPE           "Ethernet using Portenta_Ethernet Library"
#elif (WIFI_USE_PORTENTA_H7 || USE_WIFI_PORTENTA_H7)
  #define SHIELD_TYPE           "Portenta_H7 WiFi"
#else
  // Default WiFi if not specified
  #define SHIELD_TYPE           "Portenta_H7 WiFi"
#endif

#define PORTENTA_H7_ASYNC_UDP_VERSION         "Portenta_H7_AsyncUDP v1.0.0"

#ifndef _PORTENTA_H7_AUDP_LOGLEVEL_
  #define _PORTENTA_H7_AUDP_LOGLEVEL_       1
#endif

#include "Portenta_H7_AsyncUDP_Debug.h"

#include "Arduino.h"
#include "IPAddress.h"
#include "Print.h"
#include <functional>


#if defined(__DOXYGEN__)
  #undef __DOXYGEN__
#endif

#include <udp.h>

#include "lwip/inet.h"
#include "lwip/igmp.h"
#include "lwip/dns.h"

#ifndef TCP_MSS
  // May have been defined as a -DTCP_MSS option on the compile line or not.
  // Arduino core 2.3.0 or earlier does not do the -DTCP_MSS option.
  // Later versions may set this option with info from board.txt.
  // However, Core 2.4.0 and up board.txt does not define TCP_MSS for lwIP v1.4
  #define TCP_MSS       MBED_CONF_LWIP_TCP_MSS        //(1460)
#endif

class AsyncUDP;
class AsyncUDPPacket;
class AsyncUDPMessage;

struct udp_pcb;
struct pbuf;

#if LWIP_VERSION_MAJOR == 1
  struct ip_addr;
  typedef struct ip_addr ip_addr_t;
#else
  struct ip4_addr;
  typedef struct ip4_addr ip_addr_t;
#endif

class AsyncUDPMessage : public Print
{
  protected:
    uint8_t *_buffer;
    size_t _index;
    size_t _size;
    
  public:
    AsyncUDPMessage(size_t size = TCP_MSS /*1460*/);
    virtual ~AsyncUDPMessage();
    
    size_t write(const uint8_t *data, size_t len);
    size_t write(uint8_t data);
    size_t space();
    uint8_t * data();
    size_t length();
    void flush();
    
    operator bool()
    {
      return _buffer != NULL;
    }
};

//////////////////////////////////

class AsyncUDPPacket : public Print
{
  protected:
    AsyncUDP *_udp;
    ip_addr_t *_localIp;
    uint16_t _localPort;
    ip_addr_t *_remoteIp;
    uint16_t _remotePort;
    uint8_t *_data;
    size_t _len;
    
  public:
    AsyncUDPPacket(AsyncUDP *udp, ip_addr_t *localIp, uint16_t localPort, ip_addr_t *remoteIp, uint16_t remotePort, uint8_t *data, size_t len);
    virtual ~AsyncUDPPacket();

    uint8_t * data();
    size_t length();
    bool isBroadcast();
    bool isMulticast();

    IPAddress localIP();
    uint16_t localPort();
    IPAddress remoteIP();
    uint16_t remotePort();

    size_t send(AsyncUDPMessage &message);

    size_t write(const uint8_t *data, size_t len);
    size_t write(uint8_t data);
};

//////////////////////////////////

typedef std::function<void(AsyncUDPPacket& packet)> AuPacketHandlerFunction;
typedef std::function<void(void * arg, AsyncUDPPacket& packet)> AuPacketHandlerFunctionWithArg;

//////////////////////////////////

class AsyncUDP : public Print
{
  protected:
    udp_pcb *_pcb;
    bool _connected;
    AuPacketHandlerFunction _handler;

    void _recv(udp_pcb *upcb, pbuf *pb, ip_addr_t *addr, uint16_t port);
#if LWIP_VERSION_MAJOR == 1
    static void _s_recv(void *arg, udp_pcb *upcb, pbuf *p, ip_addr_t *addr, uint16_t port);
#else
    static void _s_recv(void *arg, udp_pcb *upcb, pbuf *p, const ip_addr_t *addr, uint16_t port);
#endif

  public:
    AsyncUDP();
    virtual ~AsyncUDP();

    void onPacket(AuPacketHandlerFunctionWithArg cb, void * arg = NULL);
    void onPacket(AuPacketHandlerFunction cb);

    bool listen(ip_addr_t *addr, uint16_t port);
    bool listen(const IPAddress addr, uint16_t port);
    bool listen(uint16_t port);

    bool listenMulticast(ip_addr_t *addr, uint16_t port, uint8_t ttl = 1);
    bool listenMulticast(const IPAddress addr, uint16_t port, uint8_t ttl = 1);

    bool connect(ip_addr_t *addr, uint16_t port);
    bool connect(const IPAddress addr, uint16_t port);

    void close();

    size_t writeTo(const uint8_t *data, size_t len, ip_addr_t *addr, uint16_t port);
    size_t writeTo(const uint8_t *data, size_t len, const IPAddress addr, uint16_t port);
    size_t write(const uint8_t *data, size_t len);
    size_t write(uint8_t data);

    size_t broadcastTo(uint8_t *data, size_t len, uint16_t port);
    size_t broadcastTo(const char * data, uint16_t port);
    size_t broadcast(uint8_t *data, size_t len);
    size_t broadcast(const char * data);

    size_t sendTo(AsyncUDPMessage &message, ip_addr_t *addr, uint16_t port);
    size_t sendTo(AsyncUDPMessage &message, const IPAddress addr, uint16_t port);
    size_t send(AsyncUDPMessage &message);

    size_t broadcastTo(AsyncUDPMessage &message, uint16_t port);
    size_t broadcast(AsyncUDPMessage &message);

    bool connected();
    operator bool();
};

#include "Portenta_H7_AsyncUDP_Debug.h"
#include "Portenta_H7_AsyncUDP_Impl.h"

#endif    //PORTENTA_H7_ASYNC_UDP_H
