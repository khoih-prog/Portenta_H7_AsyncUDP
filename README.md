# Portenta_H7_AsyncUDP


[![arduino-library-badge](https://www.ardu-badge.com/badge/Portenta_H7_AsyncUDP.svg?)](https://www.ardu-badge.com/Portenta_H7_AsyncUDP)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/Portenta_H7_AsyncUDP.svg)](https://github.com/khoih-prog/Portenta_H7_AsyncUDP/releases)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/Portenta_H7_AsyncUDP.svg)](http://github.com/khoih-prog/Portenta_H7_AsyncUDP/issues)

<a href="https://www.buymeacoffee.com/khoihprog6" target="_blank"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-yellow.png" alt="Buy Me A Coffee" style="height: 60px !important;width: 217px !important;" ></a>

---
---

## Table of Contents


* [Why do we need this Portenta_H7_AsyncUDP library](#why-do-we-need-this-Portenta_H7_AsyncUDP-library)
  * [Features](#features)
  * [Why Async is better](#why-async-is-better)
  * [Currently supported Boards](#currently-supported-boards)
* [Changelog](changelog.md)
* [Prerequisites](#prerequisites)
* [Installation](#installation)
  * [Use Arduino Library Manager](#use-arduino-library-manager)
  * [Manual Install](#manual-install)
  * [VS Code & PlatformIO](#vs-code--platformio)
* [Packages' Patches](#packages-patches)
  * [1. For Portenta_H7 boards using Arduino IDE in Linux](#1-for-portenta_h7-boards-using-arduino-ide-in-linux)
* [HOWTO Setting up the Async UDP Client](#howto-setting-up-the-async-udp-client)
* [Examples](#examples)
  * [1. For Vision-shield Ethernet](#1-for-Vision-shield-Ethernet)
    * [ 1. AsyncUDPClient](examples/Ethernet/AsyncUDPClient)
    * [ 2. AsyncUdpNTPClient](examples/Ethernet/AsyncUdpNTPClient)
    * [ 3. AsyncUdpSendReceive](examples/Ethernet/AsyncUdpSendReceive)
    * [ 4. AsyncUDPServer](examples/Ethernet/AsyncUDPServer)
    * [ 5. AsyncUDPMulticastServer](examples/Ethernet/AsyncUDPMulticastServer)
  * [2. Python test program](#2-Python-test-program)
    * [ 1. UDP_packet_send.py](examples/UDP_packet_send/UDP_packet_send.py)
* [Example AsyncUdpNTPClient](#example-asyncudpntpclient)
  * [1. File AsyncUdpNTPClient.ino](#1-file-asyncudpntpclientino)
  * [2. File defines.h](#2-file-definesh) 
* [Debug Terminal Output Samples](#debug-terminal-output-samples)
  * [1. AsyncUdpNTPClient on PORTENTA_H7_M7 using Ethernet](#1-asyncudpntpclient-on-PORTENTA_H7_M7-using-Ethernet)
  * [2. AsyncUDPServer on PORTENTA_H7_M7 using Ethernet](#2-AsyncUDPServer-on-PORTENTA_H7_M7-using-Ethernet)
  * [3. AsyncUDPMulticastServer on PORTENTA_H7_M7 using Ethernet](#3-AsyncUDPMulticastServer-on-PORTENTA_H7_M7-using-Ethernet)
* [Debug](#debug)
* [Troubleshooting](#troubleshooting)
* [Issues](#issues)
* [TO DO](#to-do)
* [DONE](#done)
* [Contributions and Thanks](#contributions-and-thanks)
* [Contributing](#contributing)
* [License](#license)
* [Copyright](#copyright)

---
---

### Why do we need this [Portenta_H7_AsyncUDP library](https://github.com/khoih-prog/Portenta_H7_AsyncUDP)

#### Features

This [Portenta_H7_AsyncUDP library](https://github.com/khoih-prog/Portenta_H7_AsyncUDP) is a fully asynchronous UDP library, designed for a trouble-free, multi-connection network environment, for **Portenta_H7 boards**. The library is easy to use and includes support for Unicast, Broadcast and Multicast environments.

This library is based on, modified from:

1. [Hristo Gochkov's ESPAsyncUDP](https://github.com/me-no-dev/ESPAsyncUDP)
2. [Khoi Hoang's AsyncUDP_STM32](https://github.com/khoih-prog/AsyncUDP_STM32)

to apply the better and faster **asynchronous** feature of the **powerful** [ESPAsyncUDP Library](https://github.com/me-no-dev/ESPAsyncUDP) into **Portenta_H7 boards** using either `Vision-shield Ethernet` or `Murata WiFi`.


#### Why Async is better

- Using asynchronous network means that you can handle **more than one connection at the same time**
- You are called once the request is ready and parsed
- When you send the response, you are **immediately ready** to handle other connections while the server is taking care of sending the response in the background
- **Speed is OMG**
- After connecting to a UDP server as an Async Client, you are **immediately ready** to handle other connections while the Client is taking care of receiving the UDP responding packets in the background.
- You are not required to check in a tight loop() the arrival of the UDP responding packets to process them.


### Currently supported Boards

1. **Portenta_H7 boards** such as Portenta_H7 Rev2 ABX00042, etc., using [**ArduinoCore-mbed mbed_portenta** core](https://github.com/arduino/ArduinoCore-mbed) using `Vision-shield Ethernet`

<p align="center">
    <img src="https://github.com/khoih-prog/Portenta_H7_AsyncUDP/blob/main/pics/Portenta_Vision.jpg">
</p>

---
---

## Prerequisites

 1. [`Arduino IDE 1.8.19+` for Arduino](https://github.com/arduino/Arduino). [![GitHub release](https://img.shields.io/github/release/arduino/Arduino.svg)](https://github.com/arduino/Arduino/releases/latest)
 2. [`ArduinoCore-mbed mbed_portenta core 2.6.1+`](https://github.com/arduino/ArduinoCore-mbed) for Arduino **Portenta_H7** boards, such as **Portenta_H7 Rev2 ABX00042, etc.**. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-mbed.svg)](https://github.com/arduino/ArduinoCore-mbed/releases/latest)
 
---

### Installation

The suggested way to install is to:

#### Use Arduino Library Manager

The best way is to use `Arduino Library Manager`. Search for `Portenta_H7_AsyncUDP`, then select / install the latest version. You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/Portenta_H7_AsyncUDP.svg?)](https://www.ardu-badge.com/Portenta_H7_AsyncUDP) for more detailed instructions.

### Manual Install

1. Navigate to [Portenta_H7_AsyncUDP](https://github.com/khoih-prog/Portenta_H7_AsyncUDP) page.
2. Download the latest release `Portenta_H7_AsyncUDP-master.zip`.
3. Extract the zip file to `Portenta_H7_AsyncUDP-master` directory 
4. Copy the whole `Portenta_H7_AsyncUDP-master` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

### VS Code & PlatformIO:

1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install [**Portenta_H7_AsyncUDP** library](https://platformio.org/lib/show/12930/Portenta_H7_AsyncUDP) by using [Library Manager](https://platformio.org/lib/show/12930/Portenta_H7_AsyncUDP/installation). Search for Portenta_H7_AsyncUDP in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)

---
---

### Packages' Patches

#### 1. For Portenta_H7 boards using Arduino IDE in Linux

  **To be able to upload firmware to Portenta_H7 using Arduino IDE in Linux (Ubuntu, etc.)**, you have to copy the file [portenta_post_install.sh](Packages_Patches/arduino/hardware/mbed_portenta/2.5.2/portenta_post_install.sh) into mbed_portenta directory (~/.arduino15/packages/arduino/hardware/mbed_portenta/2.5.2/portenta_post_install.sh). 
  
  Then run the following command using `sudo`
  
```
$ cd ~/.arduino15/packages/arduino/hardware/mbed_portenta/2.5.2
$ chmod 755 portenta_post_install.sh
$ sudo ./portenta_post_install.sh
```

This will create the file `/etc/udev/rules.d/49-portenta_h7.rules` as follows:

```
# Portenta H7 bootloader mode UDEV rules

SUBSYSTEMS=="usb", ATTRS{idVendor}=="2341", ATTRS{idProduct}=="035b", GROUP="plugdev", MODE="0666"
```

Supposing the ArduinoCore-mbed core version is 2.5.2. Now only one file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/mbed_portenta/2.5.2/portenta_post_install.sh`

Whenever a new version is installed, remember to copy this files into the new version directory. For example, new version is x.yy.zz

This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/mbed_portenta/x.yy.zz/portenta_post_install.sh`


---
---

## HOWTO Setting up the Async UDP Client

```cpp
#define USE_ETHERNET_PORTENTA_H7        true

#include <Portenta_Ethernet.h>
#include <Ethernet.h>
#warning Using Portenta_Ethernet lib for Portenta_H7.

#include <Portenta_H7_AsyncUDP.h>

byte mac[] =  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x01 };

// 0.ca.pool.ntp.org
IPAddress timeServerIP = IPAddress(208, 81, 1, 244);
// time.nist.gov
//IPAddress timeServerIP = IPAddress(132, 163, 96, 1);

#define NTP_REQUEST_PORT      123

const int NTP_PACKET_SIZE = 48;       // NTP timestamp is in the first 48 bytes of the message

byte packetBuffer[NTP_PACKET_SIZE];   // buffer to hold incoming and outgoing packets

// A UDP instance to let us send and receive packets over UDP
AsyncUDP Udp;

// send an NTP request to the time server at the given address
void createNTPpacket(void)
{
  ...
}

void sendNTPPacket(void)
{
  createNTPpacket();
  //Send unicast
  Udp.write(packetBuffer, sizeof(packetBuffer));
}

void parsePacket(AsyncUDPPacket packet)
{
  ...
}

void setup()
{
  ...
  
  //NTP requests are to port NTP_REQUEST_PORT = 123
  if (Udp.connect(timeServerIP, NTP_REQUEST_PORT))
  {
    // Setting up Async packet Handler
    Udp.onPacket([](AsyncUDPPacket packet)
    {
      parsePacket(packet);
    });
  }
}

void loop()
{
  sendNTPPacket();

  // wait 60 seconds before asking for the time again
  delay(60000);
}
```

---
---

### Examples

#### 1. For Vision-shield Ethernet

 1. [AsyncUDPClient](examples/Ethernet/AsyncUDPClient)
 2. [AsyncUdpNTPClient](examples/Ethernet/AsyncUdpNTPClient)
 3. [AsyncUdpSendReceive](examples/Ethernet/AsyncUdpSendReceive) 
 4. [AsyncUDPServer](examples/Ethernet/AsyncUDPServer)
 5. [AsyncUDPMulticastServer](examples/Ethernet/AsyncUDPMulticastServer)

#### 2. Python test program

  1. [UDP_packet_send.py](examples/UDP_packet_send/UDP_packet_send.py)
    
    
---

### Example [AsyncUdpNTPClient](examples/Ethernet/AsyncUdpNTPClient)

#### 1. File [AsyncUdpNTPClient.ino](examples/Ethernet/AsyncUdpNTPClient/AsyncUdpNTPClient.ino)


```cpp
#include "defines.h"
#include <time.h>

// 0.ca.pool.ntp.org
IPAddress timeServerIP = IPAddress(208, 81, 1, 244);
// time.nist.gov
//IPAddress timeServerIP = IPAddress(132, 163, 96, 1);

#define NTP_REQUEST_PORT      123

//char timeServer[] = "time.nist.gov";  // NTP server
char timeServer[] = "0.ca.pool.ntp.org";

const int NTP_PACKET_SIZE = 48;       // NTP timestamp is in the first 48 bytes of the message

byte packetBuffer[NTP_PACKET_SIZE];   // buffer to hold incoming and outgoing packets

// A UDP instance to let us send and receive packets over UDP
AsyncUDP Udp;

// send an NTP request to the time server at the given address
void createNTPpacket()
{
  Serial.println("============= createNTPpacket =============");

  // set all bytes in the buffer to 0
  memset(packetBuffer, 0, NTP_PACKET_SIZE);
  // Initialize values needed to form NTP request
  // (see URL above for details on the packets)

  packetBuffer[0]   = 0b11100011;   // LI, Version, Mode
  packetBuffer[1]   = 0;     // Stratum, or type of clock
  packetBuffer[2]   = 6;     // Polling Interval
  packetBuffer[3]   = 0xEC;  // Peer Clock Precision
  
  // 8 bytes of zero for Root Delay & Root Dispersion
  packetBuffer[12]  = 49;
  packetBuffer[13]  = 0x4E;
  packetBuffer[14]  = 49;
  packetBuffer[15]  = 52;
}

void parsePacket(AsyncUDPPacket packet)
{
  struct tm  ts;
  char       buf[80];
  
  memcpy(packetBuffer, packet.data(), sizeof(packetBuffer));

  Serial.print("Received UDP Packet Type: ");
  Serial.println(packet.isBroadcast() ? "Broadcast" : packet.isMulticast() ? "Multicast" : "Unicast");
  Serial.print("From: ");
  Serial.print(packet.remoteIP());
  Serial.print(":");
  Serial.print(packet.remotePort());
  Serial.print(", To: ");
  Serial.print(packet.localIP());
  Serial.print(":");
  Serial.print(packet.localPort());
  Serial.print(", Length: ");
  Serial.print(packet.length());
  Serial.println();

  unsigned long highWord = word(packetBuffer[40], packetBuffer[41]);
  unsigned long lowWord = word(packetBuffer[42], packetBuffer[43]);

  // combine the four bytes (two words) into a long integer
  // this is NTP time (seconds since Jan 1 1900):
  unsigned long secsSince1900 = highWord << 16 | lowWord;
  
  Serial.print(F("Seconds since Jan 1 1900 = "));
  Serial.println(secsSince1900);

  // now convert NTP time into )everyday time:
  Serial.print(F("Epoch/Unix time = "));
  
  // Unix time starts on Jan 1 1970. In seconds, that's 2208988800:
  const unsigned long seventyYears = 2208988800UL;
  
  // subtract seventy years:
  unsigned long epoch = secsSince1900 - seventyYears;
  time_t epoch_t = epoch;   //secsSince1900 - seventyYears;
 
  // print Unix time:
  Serial.println(epoch);

  // print the hour, minute and second:
  Serial.print(F("The UTC/GMT time is "));       // UTC is the time at Greenwich Meridian (GMT)

  ts = *localtime(&epoch_t);
  strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S %Z", &ts);
  Serial.println(buf);
}

void sendNTPPacket()
{
  createNTPpacket();

  Serial.println("Sending UDP Packet");
  
  //Send unicast
  Udp.write(packetBuffer, sizeof(packetBuffer));

  Serial.println("Sent UDP Packet");
}

void setup()
{
  Serial.begin(115200);
  while (!Serial);

  Serial.print("\nStart AsyncUdpNTPClient on "); Serial.print(BOARD_NAME);
  Serial.print(" with "); Serial.println(SHIELD_TYPE);
  Serial.println(PORTENTA_H7_ASYNC_UDP_VERSION);

  ///////////////////////////////////

  // start the ethernet connection and the server
  // Use random mac
  uint16_t index = millis() % NUMBER_OF_MAC;

  // Use Static IP
  //Ethernet.begin(mac[index], ip);
  // Use DHCP dynamic IP and random mac
  Ethernet.begin(mac[index]);

  if (Ethernet.hardwareStatus() == EthernetNoHardware)
  {
    Serial.println("No Ethernet found. Stay here forever");

    while (true)
    {
      delay(1); // do nothing, no point running without Ethernet hardware
    }
  }

  if (Ethernet.linkStatus() == LinkOFF)
  {
    Serial.println("Not connected Ethernet cable");
  }

  Serial.print(F("Using mac index = "));
  Serial.println(index);

  Serial.print(F("Connected! IP address: "));
  Serial.println(Ethernet.localIP());

  ///////////////////////////////////

  //NTP requests are to port NTP_REQUEST_PORT = 123
  if (Udp.connect(timeServerIP, NTP_REQUEST_PORT))
  {
    Serial.println("UDP connected");

    Udp.onPacket([](AsyncUDPPacket packet)
    {
      parsePacket(packet);
    });
  }
}

void loop()
{
  sendNTPPacket();

  // wait 60 seconds before asking for the time again
  delay(60000);
}
```

#### 2. File [defines.h](examples/Ethernet/AsyncUdpNTPClient/defines.h)

```cpp
#ifndef defines_h
#define defines_h

#if !( defined(ARDUINO_PORTENTA_H7_M7) || defined(ARDUINO_PORTENTA_H7_M4) )
  #error For Portenta_H7 only
#endif

#define PORTENTA_H7_AUDP_DEBUG_PORT      Serial

// Use from 0 to 4. Higher number, more debugging messages and memory usage.
#define _PORTENTA_H7_AUDP_LOGLEVEL_      1

#define USE_ETHERNET_PORTENTA_H7        true

#include <Portenta_Ethernet.h>
#include <Ethernet.h>
#warning Using Portenta_Ethernet lib for Portenta_H7.

#include <Portenta_H7_AsyncUDP.h>

// Enter a MAC address and IP address for your controller below.
#define NUMBER_OF_MAC      20

byte mac[][NUMBER_OF_MAC] =
{
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x01 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x02 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x03 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x04 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x05 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x06 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x07 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x08 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x09 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x0A },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x0B },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x0C },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x0D },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x0E },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x0F },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x10 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x11 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x12 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x13 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x14 },
};


#endif    //defines_h
```

---

### Debug Terminal Output Samples

#### 1. AsyncUdpNTPClient on PORTENTA_H7_M7 using Ethernet

This is terminal debug output when running [AsyncUdpNTPClient](examples/Ethernet/AsyncUdpNTPClient) on **PORTENTA_H7_M7 using Ethernet and Portenta_Ethernet Library**. It connects to NTP Server `0.ca.pool.ntp.org` (IP=`208.81.1.244:123`) using Portenta_H7_AsyncUDP library, and requests NTP time every 60s. The packet is then **received and processed asynchronously** to print current UTC/GMT time.

```
Start AsyncUdpNTPClient on PORTENTA_H7_M7 with Ethernet using Portenta_Ethernet Library
Portenta_H7_AsyncUDP v1.0.0
Using mac index = 5
Connected! IP address: 192.168.2.87
UDP connected
============= createNTPpacket =============
Sending UDP Packet
Sent UDP Packet
Received UDP Packet Type: Unicast
From: 208.81.1.244:123, To: 192.168.2.87:58997, Length: 48
Seconds since Jan 1 1900 = 3842738319
Epoch/Unix time = 1633749519
The UTC/GMT time is Sat 2021-10-09 03:18:39 GMT
============= createNTPpacket =============
Sending UDP Packet
Sent UDP Packet
Received UDP Packet Type: Unicast
From: 208.81.1.244:123, To: 192.168.2.87:58997, Length: 48
Seconds since Jan 1 1900 = 3842738378
Epoch/Unix time = 1633749578
The UTC/GMT time is Sat 2021-10-09 03:19:38 GMT
```

---

#### 2. AsyncUDPServer on PORTENTA_H7_M7 using Ethernet

This is terminal debug output when running [AsyncUDPServer](examples/Ethernet/AsyncUDPServer) on **PORTENTA_H7_M7 using Ethernet and Portenta_Ethernet Library**. It receives UDP packets from a PC running test Python program [UDP_packet_send.py](examples/UDP_packet_send/UDP_packet_send.py) to send UDP packets.

```
Start AsyncUDPServer on PORTENTA_H7_M7 with Ethernet using Portenta_Ethernet Library
Portenta_H7_AsyncUDP v1.0.0
Using mac index = 10
Connected! IP address: 192.168.2.87
UDP Listening on IP: 192.168.2.87
UDP Packet Type: Unicast, From: 192.168.2.30:33380, To: 192.168.2.87:1234, Length: 15, Data: Hello, Portenta!
```

---

#### 3. AsyncUDPMulticastServer on PORTENTA_H7_M7 using Ethernet

This is terminal debug output when running [AsyncUDPMulticastServer](examples/Ethernet/AsyncUDPMulticastServer) on **PORTENTA_H7_M7 using Ethernet and Portenta_Ethernet Library**. It receives UDP packets from from a PC running test Python program [UDP_packet_send.py](examples/UDP_packet_send/UDP_packet_send.py) to send UDP packets.

```
Start AsyncUDPMulticastServer on PORTENTA_H7_M7 with Ethernet using Portenta_Ethernet Library
Portenta_H7_AsyncUDP v1.0.0
Using mac index = 16
Connected! IP address: 192.168.2.87
UDP Listening on IP: 192.168.2.87
UDP Packet Type: Unicast, From: 192.168.2.30:50119, To: 192.168.2.87:1234, Length: 16, Data: Hello, Portenta!
```

---
---

### Debug

Debug is enabled by default on Serial. To disable, use level 0

```cpp
#define PORTENTA_H7_AUDP_DEBUG_PORT      Serial

// Use from 0 to 4. Higher number, more debugging messages and memory usage.
#define _PORTENTA_H7_AUDP_LOGLEVEL_      0
```

You can also change the debugging level from 0 to 4, default is 1 to output only error messages

```cpp
#define PORTENTA_H7_AUDP_DEBUG_PORT      Serial

// Use from 0 to 4. Higher number, more debugging messages and memory usage.
#define _PORTENTA_H7_AUDP_LOGLEVEL_      4
```

---

### Troubleshooting

If you get compilation errors, more often than not, you may need to install a newer version of Arduino IDE, the Arduino `STM32` core or depending libraries.

Sometimes, the library will only work if you update the `STM32` core to the latest version because I am always using the latest cores /libraries.

---
---


### Issues ###

Submit issues to: [Portenta_H7_AsyncUDP issues](https://github.com/khoih-prog/Portenta_H7_AsyncUDP/issues)

---

## TO DO

 1. Fix bug. Add enhancement
 2. Add support to `Murata` WiFi


## DONE

 1. Add support to Portenta_H7 using `Vision-shield Ethernet`
 2. Add Table of Contents

---
---

### Contributions and Thanks

1. Based on and modified from [Hristo Gochkov's ESPAsyncUDP](https://github.com/me-no-dev/ESPAsyncUDP). Many thanks to [Hristo Gochkov](https://github.com/me-no-dev) for great [ESPAsyncUDP Library](https://github.com/me-no-dev/ESPAsyncUDP)


<table>
  <tr>
    <td align="center"><a href="https://github.com/me-no-dev"><img src="https://github.com/me-no-dev.png" width="100px;" alt="me-no-dev"/><br /><sub><b>⭐️⭐️ Hristo Gochkov</b></sub></a><br /></td>
  </tr> 
</table>

---

### Contributing

If you want to contribute to this project:
- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

---

### License

- The library is licensed under [GPLv3](https://github.com/khoih-prog/Portenta_H7_AsyncWebServer/blob/main/LICENSE)

---

## Copyright

Copyright 2021- Khoi Hoang


