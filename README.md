# Portenta_H7_AsyncUDP Library


[![arduino-library-badge](https://www.ardu-badge.com/badge/Portenta_H7_AsyncUDP.svg?)](https://www.ardu-badge.com/Portenta_H7_AsyncUDP)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/Portenta_H7_AsyncUDP.svg)](https://github.com/khoih-prog/Portenta_H7_AsyncUDP/releases)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/Portenta_H7_AsyncUDP.svg)](http://github.com/khoih-prog/Portenta_H7_AsyncUDP/issues)


<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-yellow.png" alt="Donate to my libraries using BuyMeACoffee" style="height: 50px !important;width: 181px !important;" ></a>
<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://img.shields.io/badge/buy%20me%20a%20coffee-donate-orange.svg?logo=buy-me-a-coffee&logoColor=FFDD00" style="height: 20px !important;width: 200px !important;" ></a>

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
    <img src="https://github.com/khoih-prog/Portenta_H7_AsyncUDP/raw/main/pics/Portenta_Vision.jpg">
</p>

---
---

## Prerequisites

 1. [`Arduino IDE 1.8.19+` for Arduino](https://github.com/arduino/Arduino). [![GitHub release](https://img.shields.io/github/release/arduino/Arduino.svg)](https://github.com/arduino/Arduino/releases/latest)
 2. [`ArduinoCore-mbed mbed_portenta core 3.4.1+`](https://github.com/arduino/ArduinoCore-mbed) for Arduino **Portenta_H7** boards, such as **Portenta_H7 Rev2 ABX00042, etc.**. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-mbed.svg)](https://github.com/arduino/ArduinoCore-mbed/releases/latest)
 
---

### Installation

The suggested way to install is to:

#### Use Arduino Library Manager

The best way is to use `Arduino Library Manager`. Search for `Portenta_H7_AsyncUDP`, then select / install the latest version. You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/Portenta_H7_AsyncUDP.svg?)](https://www.ardu-badge.com/Portenta_H7_AsyncUDP) for more detailed instructions.

### Manual Install

1. Navigate to [Portenta_H7_AsyncUDP](https://github.com/khoih-prog/Portenta_H7_AsyncUDP) page.
2. Download the latest release `Portenta_H7_AsyncUDP-main.zip`.
3. Extract the zip file to `Portenta_H7_AsyncUDP-main` directory 
4. Copy the whole `Portenta_H7_AsyncUDP-main` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

### VS Code & PlatformIO:

1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install [**Portenta_H7_AsyncUDP** library](https://registry.platformio.org/libraries/khoih-prog/Portenta_H7_AsyncUDP) by using [Library Manager](https://registry.platformio.org/libraries/khoih-prog/Portenta_H7_AsyncUDP/installation). Search for Portenta_H7_AsyncUDP in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)

---
---

### Packages' Patches

#### 1. For Portenta_H7 boards using Arduino IDE in Linux

  **To be able to upload firmware to Portenta_H7 using Arduino IDE in Linux (Ubuntu, etc.)**, you have to copy the file [portenta_post_install.sh](Packages_Patches/arduino/hardware/mbed_portenta/3.4.1/portenta_post_install.sh) into mbed_portenta directory (~/.arduino15/packages/arduino/hardware/mbed_portenta/3.4.1/portenta_post_install.sh). 
  
  Then run the following command using `sudo`
  
```
$ cd ~/.arduino15/packages/arduino/hardware/mbed_portenta/3.4.1
$ chmod 755 portenta_post_install.sh
$ sudo ./portenta_post_install.sh
```

This will create the file `/etc/udev/rules.d/49-portenta_h7.rules` as follows:

```
# Portenta H7 bootloader mode UDEV rules

SUBSYSTEMS=="usb", ATTRS{idVendor}=="2341", ATTRS{idProduct}=="035b", GROUP="plugdev", MODE="0666"
```

Supposing the ArduinoCore-mbed core version is 3.4.1. Now only one file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/mbed_portenta/3.4.1/portenta_post_install.sh`

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

https://github.com/khoih-prog/Portenta_H7_AsyncUDP/blob/99ede4dcccd41bf80d5ebc60d82f09aa19bc5091/examples/Ethernet/AsyncUdpNTPClient/AsyncUdpNTPClient.ino#L24-L191


#### 2. File [defines.h](examples/Ethernet/AsyncUdpNTPClient/defines.h)

https://github.com/khoih-prog/Portenta_H7_AsyncUDP/blob/99ede4dcccd41bf80d5ebc60d82f09aa19bc5091/examples/Ethernet/AsyncUdpNTPClient/defines.h#L18-L66

---

### Debug Terminal Output Samples

#### 1. AsyncUdpNTPClient on PORTENTA_H7_M7 using Ethernet

This is terminal debug output when running [AsyncUdpNTPClient](examples/Ethernet/AsyncUdpNTPClient) on **PORTENTA_H7_M7 using Ethernet and Portenta_Ethernet Library**. It connects to NTP Server `0.ca.pool.ntp.org` (IP=`208.81.1.244:123`) using Portenta_H7_AsyncUDP library, and requests NTP time every 60s. The packet is then **received and processed asynchronously** to print current UTC/GMT time.

```cpp
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

```cpp
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

```cpp
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

Copyright (c) 2021- Khoi Hoang


