# 🤖 WRO-2026-Future-Engineers

Official repository of Team Los Grises Superiores for the **Future Engineers – World Robot Olympiad 2026**.  
<div align="center">
<img width="1000" height="500" alt="team-image" src="https://github.com/christopherperezcortes/WRO-2026-Future-Engineers/blob/8448c0a9a9a7654d25a41275f1191a06cfbc1f03/LOS%20GRISES.png" />
</div>

---

## 📸 Team photo
<div align="center">
  <img width="500" height="500" alt="team-photo" src="" />
</div>

---

## 👥 Team Members

### Eduardo Alvarado Gonzalez
<div align="center">
<img width="200" height="200" alt="Eduardo Gonzalez" src="https://github.com/user-attachments/assets/20ccfb81-0bc1-4147-aa43-fefe649a55c0" />
</div>

**Role:** Coach and founder

An engineer and professor founded the **Los Grises Superiores** in 2014, since then with outstanding national and international participations.

---

### Christopher Pérez cortés
**Age:** 14
<div align="center">
  <img width="200" height="200" alt="Christopher Pérez photo" src="" />
</div>

**Role:** Programming and Electronics 
I started working at the **Robotics Club** at the “Prof. Moisés Sáenz Garza” Teacher Training College just a few months ago. I took a crash course in robotics and was then selected to join the club. I’m currently in my third year of middle school and have learned a lot about **electronics, programming, and 3D modeling**. This is my first WRO tournament 

---

### Bárbara Daiana García Balboa
**Age:** 13
<div align="center">
  <img width="200" height="200" alt="Bárbara Daiana photo" src="h" />
</div>

**Role:** design and assembly

I have been a member of the robotics club at the 'Profr. Moisés Sáenz Garza' Normal School for two months. I started after taking two intensive robotics courses, eventually joining this team for my first competition at WRO 2026.

### Paulina Ibarra Martínez
**Age:** 20
<div align="center">
  <img width="200" height="200" alt="Paulina Martinez photo" src="" />
</div>

**Role:** design and construction

I have been part of the **Robotics Club** at *Escuela Normal Superior “Profr. Moisés Sáenz Garza”* for three years, participating in **two Mexican Robotics Tournaments**, achieving **5th place** in the most recent one. Starting in 2024, I became a **junior coach**, achieving **third place** in WRO 2024 and **first place nationally** in the Mexican Robotics Tournament 2025.

---

## 📚 Contents
- [Project Overview](#project-overview)
- [Vehicle Photos](#vehicle-photos)
- [Components and Hardware](#components-and-hardware)
- [Mobility Management](#mobility-management)
  - [Chassis](#chassis)
  - [Steering System](#steering-system)
  - [Movement and Traction System](#movement-and-traction-system)
  - [Differential](#about-differential)
- [Power and Sense Management](#power-and-sense-management)
  - [Power Management](#power-management)
  - [Sense Management](#sense-management)
- [Obstacle Management](#obstacle-management)
  - [Vision System](#vision-system)
- [Calibration](#calibration)
- [Detection and Avoidance Strategies](#detection-and-avoidance-strategies)
- [WRO 2025 Competition Info](#wro-2025-competition-info)

---

---

## Project Overview

### Abstract

We present the **development and implementation of an autonomous vehicle** designed for the **World Robot Olympiad 2025 – Future Engineers** category.  
The competition challenges participants to design, construct, and program a self-driving car capable of completing specific tasks under variable environmental and rule-based conditions.

The **Future Engineers** category consists of **two main challenges**:

1. **Open Challenge**  
- The vehicle must autonomously complete **three laps** on a predefined track.  
- The **starting position** and **driving direction** (clockwise or counterclockwise) are **randomly assigned** before each run.

2. **Obstacle Challenge**  
- Similar to the Open Challenge, but the vehicle must **detect and react to colored pillars** acting as traffic signals:  
    - **Red pillars → Turn right**  
    - **Green pillars → Turn left**


**Documentation:**  
Documentation is a critical component of the challenge, as it reflects the team’s **engineering process**. Teams are required to maintain a **public repository** including code, CAD files, logs, and other technical documentation.

For full rules and official specifications:  
🔗 [WRO 2025 Future Engineers – General Rules (PDF)](https://wro-association.org/wp-content/uploads/WRO-2025-Future-Engineers-Self-Driving-Cars-General-Rules.pdf)

---

## Vehicle Photos

<div align="center">

| Front | Back |
|:--:|:--:|
<img width="500" height="500" alt="image" src="" /> | <img width="500" height="500" alt="image" src="" /> |



| Bottom | Top |
|:--:|:--:|
| <img width="500" height="500" alt="Top" src="" /> | <img width="500" height="500" alt="Bottom" src="" /> |

| Left | Right |
|:--:|:--:|
| <img width="500" height="500" alt="Left" src="" /> | <img width="500" height="500" alt="Right" src="" /> |

</div>

---

## 🎥 Project Videos

<div align="center">

### 🧩 Open Challenge  
[![Watch the video](https://img.shields.io/badge/▶️%20Watch%20on-YouTube-red?logo=youtube&style=for-the-badge)](https://youtu.be/1m1DtpiEMQE)

---

### 🚧 Obstacle Challenge  
[![Watch the video](https://img.shields.io/badge/▶️%20Watch%20on-YouTube-red?logo=youtube&style=for-the-badge)](https://youtu.be/9271onx2KII?si=sX-anvJybtzA0IHB)

</div>

---

---
| Component | Description | Image | Purchase Link |
|-----------|-------------|-------|----------------|
| ** HuskyLens AI Computer Vision Camera** | This camera features built-in artificial intelligence and is designed to enable robots and electronic projects to see, recognize, and track objects easily without complex programming. | <div align="center"><img width="500" height="300" alt="Huskylens" src="https://github.com/christopherperezcortes/IMAGENES/blob/0ed4c77508b2cd74c5349e8b7ef828bcb97ae8f8/D_NQ_NP_819627-MLA99992057823_112025-O.webp" /></div> | [Buy here](https://www.dfrobot.com/product-2995.html) |
| **HC-SR04 Ultrasonic Sensor** | Distance measurement sensor. | <div align="center"><img width="500" height="300" alt="HC-SR04" src="https://github.com/user-attachments/assets/f55c9c1f-b8f7-4d51-9b24-01f51de329b8" /></div> | [Buy here](https://uelectronics.com/producto/sensor-ultrasonico-hc-sr04/) |
| **Arduino Nano** | ATmega328-based microcontroller for control tasks. | <div align="center"><img width="500" height="300" alt="Arduino Nano" src="https://github.com/user-attachments/assets/22e8f59c-909d-4ff2-b637-dc03e15f4de6" /></div> | [Buy here](https://www.steren.com.mx/placa-de-desarrollo-nano.html) |
| **Mini 560 Step-Down Regulator** | Converts a higher voltage power source to a lower voltage efficiently. | <div align="center"><img width="500" height="300" alt="Mini 560" src="https://github.com/user-attachments/assets/51c8abdf-98bc-41fd-a258-7c256c0dce49" /></div> | [Buy here](https://uelectronics.com/producto/mini-560-regulador-step-down/?srsltid=AfmBOooF0lIfgnTp_5_7mmjziZz1XquqOzfXZdxR7m-WYIGU82qSsVjV) |
| **IMU MPU6050 6 degrees of freedom** | The MPU6050 is a 6-axis IMU sensor that measures acceleration and tilt (accelerometer) and rotation (gyroscope). It communicates via I2C, is small and affordable, and is used in robots, drones, and motion systems to detect position and orientation. | <div align="center"><img width="500" height="300" alt="Huskylens" src="https://github.com/christopherperezcortes/IMAGENES/blob/5c8409845c6087cf059adcb8559e2c516317ad9c/AR0277-MPU6050-min-800x800.jpg" /></div> | [Buy here](https://uelectronics.com/producto/imu-mpu6050-6-grados-de-libertad/) |
| **Driver TB6612FNG** | The TB6612FNG is a driver that allows you to control the speed and direction of DC motors with Arduino using PWM; it is efficient, compact, and is used in robots to drive the wheels. | <div align="center"><img width="500" height="300" alt="Huskylens" src="https://github.com/christopherperezcortes/IMAGENES/blob/5c8409845c6087cf059adcb8559e2c516317ad9c/driver-tb6612fng.jpg" /></div> | [Buy here](https://uelectronics.com/producto/doble-puente-h-tb6612fng/) |

## Mobility Management

### Chassis
The main chassis is 3D-printed. When designing it, we had to take many factors into account; primarily, we chose a more compact and efficient model so it could navigate the course without colliding with obstacles or walls. The model was designed in Onshape due to its extensive features.
In the steering area, we left space so the wheels could turn freely without interference from the chassis or components. Additionally, we designed an extra triangular piece so the servo motor could fit into the LEGO pieces, ensuring the servo was securely fastened and the movement was stable. 

<div align="center">
<img width="500" height="500" alt="CHASIS" src="https://github.com/christopherperezcortes/IMAGENES/blob/f4b7efd2b9f949eae8dd6a845992508e85c39529/Captura%20de%20pantalla%202026-04-10%20122143.png" />
</div>


The parts were manufactured using a 3D printer with PLA, a common material for 3D printing, but they were shipped separately


<div align="center">
<img width="500" height="5000" alt="foto de impresion" src="https://github.com/christopherperezcortes/IMAGENES/blob/f4b7efd2b9f949eae8dd6a845992508e85c39529/Captura%20de%20pantalla%202026-04-10%20122143.png" />
</div>


### Microcontroller(Arduino nano)
<div align="center">
<img width="500" height="500" alt="Arduino Nano large" src="https://github.com/user-attachments/assets/0d45ec5e-d666-4185-be01-94dc062a9f37" />
</div>

**Specifications:**

| Specification            | Description |
|---------------------------|-------------|
| **Microcontroller**       | ATmega328P |
| **Operating Voltage**     | 5 V |
| **Input Voltage (recommended)** | 7–12 V |
| **Input Voltage (limit)** | 6–20 V |
| **Digital I/O Pins**      | 14 (6 PWM outputs) |
| **Analog Input Pins**     | 8 |
| **DC Current per I/O Pin** | 40 mA |
| **Flash Memory**          | 32 KB (2 KB used by bootloader) |
| **SRAM**                  | 2 KB |
| **EEPROM**                | 1 KB |
| **Clock Speed**           | 16 MHz |
| **USB Connection**        | Mini USB |
| **Dimensions**            | 45 mm x 18 mm |
| **Weight**                | ~7 g |

The Arduino Nano is a compact,microcontroller board based on the ATmega328P. Despite its small size, it offers full functionality with 14 digital I/O pins, 8 analog inputs, and a 16 MHz clock speed.
It operates at 5V and can be powered through a Mini USB connection, a regulated 5V pin, or an external 7–12V input,

## HuskyLens AI Computer Vision Camera (SEN0305)
<div align="center">
<img width="600" height="600" alt="HuskyLens AI" src="https://github.com/christopherperezcortes/IMAGENES/blob/0ed4c77508b2cd74c5349e8b7ef828bcb97ae8f8/D_NQ_NP_819627-MLA99992057823_112025-O.webp" />
</div



## Specifications

| Feature              | Details                                                                 |
|----------------------|-------------------------------------------------------------------------|
| Processor            | Kendryte K210, 400MHz, 64-Bit Dual Core RISC-V             |
| Image Sensor         | Standard Version: OV2640, 2.0 Megapixel Camera Enhanced Version: OV5640, 5.0 Megapixel Camera                   |
| Resolution           | 320 x 240 pixels                           |
| Frame Rate           |  30 fps                               |
| Image Formats        | OV2640                                  |
| Connectivity         | UART (Serial) or I2C                                  |
| Power Supply         | 3.3 V to 5.0 V.                           |
| Onboard LEDs         | 2 white LEDs (fill lights) and 1 RGB LED                                 |
| Programming Language | C++ and Python                                               |
| Operating Voltage    | 3.3V a 5.0V DC                                                                    |
| Dimensions           | 52mm * 44.5mm                                                    |
| Weight               | 96g                                                       |

HuskyLens is an AI-powered camera that’s very easy to use. It features a built-in display and a menu system for configuration, so you can start using it right away without any programming. It offers several operating modes:

· Face recognition

· Object recognition

· Line tracking

· Object trackin

· Color recognition

· QR code-based tag identification.

It uses a Kendryte K210 AI processor and features I2C and UART connections to interact with Arduino, micro:bit, or Raspberry Pi without having to deal with the complexities of programming AI algorithms.

 IMPORTANTE PONER:  The camera is mounted at a 70° angle on the highest point of the vehicle. This position was selected to maximize the field of view, allowing the vehicle to better detect obstacles and monitor the track, covering a larger area and facilitating the identification of the designated parking zone. Initially, the camera was positioned at the front of the vehicle, above the steering system. However, it faced visibility issues, as the field of view was limited, which led to errors when avoiding the pillars. 
