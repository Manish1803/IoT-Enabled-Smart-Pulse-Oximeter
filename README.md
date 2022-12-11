# IoT Enabled Smart Pulse Oximeter

This was our First-Year Engineering Project Based Learning project.

In this project, we made a Smart Health Monitoring
System that can measure SpO2 (percentage of
peripheral oxygen in the blood) and heart rate in BPM
(Beat Per Minute). This device can be used by everyone
to monitor their heart rate and blood oxygen levels
during a workout. The Best part of this project is that
you can connect this device to an app (Blynk) that will
record and regularly update the data for both SPO2 &
BPM on the cloud.


## Features

- IoT Integrated
- Continous Sp02 and heart rate monitoring
- Live graph of the vitals measured
- The record can be viewed anywhere in the world

## Electronics Required
 - MAX30100 sensor
 - ESP01 microcontroller
 - NodeMCU (for programming of the ESP01)
 - USB to TTL converter
 - 3.7V LiPO battery
 - 3.3V Buck - boost converter
 - TP4056 Module
 - Push botton switch
 - Band switch

## Circuit Diagram

![Circuit Diagram](https://user-images.githubusercontent.com/59637955/206894343-efe895c7-9b88-4904-b052-22766611ef08.jpg)

## Use

The project uses a ESP8266 microcontroller so clone the repository and open the code in Arduino IDE

```bash
  git clone https://github.com/deven322/IoT-Enabled-Smart-Pulse-Oximeter.git
```
You will also need a library to upload wifi SSID and Password over the air

```bash
  git clone https://github.com/techiesms/OTABlynkCredentials
```    
The other libraries need are:

- MAX30100
- Blynk
- ESP8266 (Automatically installs after you install ESP8266 board in Arduino IDE)

All the above libraries can be found in the library manager. 

## 🔗 Links
[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/deven-patil-067530209/)


## Contributors and Team Members

- [Manish Patil](https://github.com/Manish1803)
- [Aniket Jagtap](https://github.com/aniketajagtap)
- Sushant Shelar
- Isha Pawar
