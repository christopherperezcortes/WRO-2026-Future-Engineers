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

| Component | Description | Image | Purchase Link |
|-----------|-------------|-------|----------------|
| ** HuskyLens Cámara de Visión Artificial IA (SEN0305)** | This camera features built-in artificial intelligence and is designed to enable robots and electronic projects to see, recognize, and track objects easily without complex programming. | <div align="center"><img width="500" height="300" alt="OpenMV Cam H7 Plus" src="https://github.com/user-attachments/assets/2f1dc12c-a2f9-4e47-b665-d9b37091a8ce" /></div> | [Buy here](https://www.dfrobot.com/product-2995.html) |
| **HC-SR04 Ultrasonic Sensor** | Distance measurement sensor. | <div align="center"><img width="500" height="300" alt="HC-SR04" src="https://github.com/user-attachments/assets/f55c9c1f-b8f7-4d51-9b24-01f51de329b8" /></div> | [Buy here](https://uelectronics.com/producto/sensor-ultrasonico-hc-sr04/) |
| **Arduino Nano** | ATmega328-based microcontroller for control tasks. | <div align="center"><img width="500" height="300" alt="Arduino Nano" src="https://github.com/user-attachments/assets/22e8f59c-909d-4ff2-b637-dc03e15f4de6" /></div> | [Buy here](https://www.steren.com.mx/placa-de-desarrollo-nano.html) |
| **Mini 560 Step-Down Regulator** | Converts a higher voltage power source to a lower voltage efficiently. | <div align="center"><img width="500" height="300" alt="Mini 560" src="https://github.com/user-attachments/assets/51c8abdf-98bc-41fd-a258-7c256c0dce49" /></div> | [Buy here](https://uelectronics.com/producto/mini-560-regulador-step-down/?srsltid=AfmBOooF0lIfgnTp_5_7mmjziZz1XquqOzfXZdxR7m-WYIGU82qSsVjV) |

