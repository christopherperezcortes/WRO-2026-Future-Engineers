# Software Architecture and Upload Guide

## Declared controller roles

| File | Hardware | Function | Inputs | Outputs | Dependencies |
|---|---|---|---|---|---|
| `esp32-main/open-challenge/ESP32_Open_Optimized.ino` | FireBeetle ESP32 DFR0478 | Open Challenge PID, recovery, BNO085 lap count and final stop | Nano I2C, BNO085 I2C, encoder | Servo, TB6612, Nano brightness | `Wire`, `Adafruit_BNO08x`, `WiFi`, `WebServer` |
| `esp32-main/obstacle-challenge/experimental/ESP32_Obstacle_Parking_4_Laps.ino` | FireBeetle ESP32 | Obstacle navigation and experimental parking | OpenMV UART, Nano I2C, BNO085, encoder | Servo, TB6612, OpenMV mode, Nano brightness | `Arduino`, `Wire`, `Adafruit_BNO08x`, `Preferences` |
| `esp32-main/obstacle-challenge/competition-candidate/ESP32_Obstacle_3_Laps_No_Parking.ino` | FireBeetle ESP32 | Exactly three obstacle laps, then stop | OpenMV UART, Nano I2C, BNO085, encoder | Servo, TB6612, Nano/OpenMV commands | Same as above |
| `nano-sensor-hub/Nano_Sensors_I2C.ino` | Classic Arduino Nano | Five ultrasonic sensors and NeoPixels | HC-SR04 echoes, I2C brightness byte | 10-byte I2C distance packet, LED data | `Wire`, `Adafruit_NeoPixel` |
| `openmv/color_corner_v6.py` | OpenMV [PENDING exact model] | Red/green pillar, black ROI, magenta wall/gap detection | Camera image, ESP32 UART commands | 13-field CSV UART frame | OpenMV `sensor`, `time`, `micropython`, `machine.UART` |
| `esp32-main/tools/servo-center/ESP32_Center_Servo.ino` | FireBeetle ESP32 | Mechanical servo centering | — | Servo PWM | ESP32 Arduino core |
| `esp32-main/tools/openmv-uart-reader/ESP32_Read_OpenMV.ino` | FireBeetle ESP32 | Bench UART validation | OpenMV UART | USB serial | ESP32 Arduino core |

## Release status

| Build | Status |
|---|---|
| Open Challenge | Functionally advanced, but Wi-Fi is enabled and the WRO start button is not implemented |
| Three-lap obstacle build | Correct lap count, but parking disabled |
| Four-lap parking build | Parking implemented, but lap sequence conflicts with the three-lap rule |
| OpenMV v6 | Current vision candidate |
| Nano 3×8 | Current source candidate; installed LED topology must be confirmed |

A final release must contain exactly one competition program for each challenge and a configuration table recording every changed constant.

## Physical connections

### ESP32

| Function | ESP32 pin |
|---|---|
| Servo signal | GPIO27 / D4 |
| TB6612 PWMA | D6 |
| TB6612 AIN2 | D7 |
| TB6612 AIN1 | D8 |
| Encoder A | D5 |
| Encoder B, Open build | D9 |
| OpenMV RX | GPIO25 / D2 |
| OpenMV TX | GPIO26 / D3 |
| I2C SDA | GPIO21 |
| I2C SCL | GPIO22 |
| Start button | **[MISSING: assign and document a safe input pin]** |

### Nano

| Function | Pin |
|---|---|
| S1 left 90° TRIG/ECHO | D2/D3 |
| S2 left 25° TRIG/ECHO | D4/D5 |
| S3 front TRIG/ECHO | D6/D7 |
| S4 right 25° TRIG/ECHO | D8/D9 |
| S5 right 90° TRIG/ECHO | D10/D11 |
| NeoPixel data | D12 |
| I2C SDA/SCL | A4/A5 |
| I2C address | `0x08` |

## Inter-controller protocols

### Nano → ESP32 I2C

The Nano is a slave at `0x08`. The ESP32 requests ten bytes:

```text
S1_LOW,S1_HIGH,S2_LOW,S2_HIGH,S3_LOW,S3_HIGH,S4_LOW,S4_HIGH,S5_LOW,S5_HIGH
```

Each value is unsigned millimetres, little-endian. `0xFFFF` means invalid/no accepted echo.

### ESP32 → Nano I2C

One byte from 0 to 100 requests the LED brightness percentage.

### OpenMV → ESP32 UART

```text
ID,X,Y,AREA,ROI,COLLISION,BLACK_WALL,
PARKING,PARKING_X,PARKING_AREA,
GAP,GAP_X,GAP_WIDTH\n
```

| Field | Meaning |
|---|---|
| `ID` | 0 none, 3 green, 5 red |
| `X` | Reference X normalized from −100 to +100 |
| `Y` | Reference Y in 0–239 pixels |
| `AREA` | Blob box area |
| `ROI` | 0 none, 1 high, 2 low |
| `COLLISION` | 0, 3 or 5 |
| `BLACK_WALL` | Central black ROI flag |
| `PARKING` | Valid wide magenta boundary |
| `PARKING_X` | Boundary center X |
| `PARKING_AREA` | Boundary area |
| `GAP` | Valid gap between two boundaries |
| `GAP_X` | Gap center X |
| `GAP_WIDTH` | Gap width in pixels |

UART is 19200 baud, 8 data bits, no parity and one stop bit.

### ESP32 → OpenMV UART

```text
P,0\n  # disable parking detection
P,1\n  # enable parking detection
T,servo,motor,S1,S2,S3,S4,S5\n  # optional display telemetry
```

## Control flow and priorities

### Open Challenge

1. Initialize I2C, BNO085, servo, motor and LEDs.
2. Collect ten stationary corridor-width samples.
3. Apply a low motor command while waiting for encoder motion.
4. After movement is detected, ramp speed for five seconds.
5. Run wall-centering PID.
6. Reduce speed near front/lateral walls.
7. Apply the 90° heading guard.
8. Reverse if S3 is critically close.
9. Count twelve confirmed corners.
10. Perform the configured final-position adjustment.
11. Stop and latch mission completion.

The current movement-detection start is not a replacement for the WRO-required pushbutton.

### Obstacle Challenge priority

Highest to lowest:

1. Final stop or parking emergency.
2. Missing distance packet/S3 invalid.
3. Front brake/reverse recovery.
4. Parking state control.
5. Valid OpenMV pillar control.
6. Ultrasonic corridor control.
7. Motor/servo output.
8. Telemetry and maintenance.

## Fallbacks

| Failure | Current response |
|---|---|
| Nano packet missing >250 ms | Stop motor |
| S3 invalid after 125 ms retention | Stop motor |
| OpenMV UART missing >500 ms | Clear target and use corridor control |
| Invalid OpenMV line | Ignore and count/report invalid frame |
| Visual collision | Limit speed to 40%; S3 authorizes reverse |
| BNO085 missing | Retry at `0x4B` and `0x4A` |
| BNO085 data stops | Reinitialize after timeout |
| Reverse lasts 2.5 s without clearance | Stop and wait |
| Critical parking sensor invalid | Active braking/cancel parking |
| Parking phase timeout | Active braking/cancel parking |

The Open build currently allows motion without BNO085 because `EXIGIR_BNO085_PARA_MOVERSE=false`. This may prevent mission completion and must be deliberately resolved after testing.

## Required toolchain record

Fill this table from the exact competition laptop:

| Tool | Version |
|---|---|
| Arduino IDE | `[PENDING]` |
| ESP32 board package | `[PENDING]` |
| Selected FireBeetle board definition | `[PENDING]` |
| Adafruit BNO08x | `[PENDING]` |
| Adafruit NeoPixel | `[PENDING]` |
| OpenMV IDE | `[PENDING]` |
| OpenMV firmware | `[PENDING]` |
| Python/MicroPython API version | `[PENDING]` |

## Upload procedure

### Arduino Nano

1. Disconnect motor power.
2. Connect the Nano by USB.
3. Select the exact Nano board and bootloader used by the physical board.
4. Install Adafruit NeoPixel.
5. Confirm the real LED count/topology.
6. Compile and upload `Nano_Sensors_I2C.ino`.
7. Verify `0x08` on an I2C scan.

### OpenMV

1. Connect OpenMV to OpenMV IDE.
2. Open `color_corner_v6.py`.
3. Confirm UART bus and pins for the exact camera.
4. Run the calibration scene.
5. Record the selected exposure and LAB statistics.
6. Save the script as the camera boot program.
7. Verify 13-field CSV frames at 19200 baud.

### ESP32

1. Install the exact board package and BNO08x library.
2. Select the FireBeetle board definition.
3. Choose one declared challenge build.
4. For competition:
   - Disable Wi-Fi.
   - Disable all Bluetooth/RF.
   - Implement the single start pushbutton.
   - Verify the correct three-lap sequence.
5. Compile and upload.
6. Test first with wheels lifted.
7. Verify servo direction, motor direction, encoder, I2C and UART.

## Competition release procedure

1. Pass the compliance checklist.
2. Record every calibration value.
3. Run the repeatability protocol.
4. Commit all source and data.
5. Create a release/tag such as `wro-2026-national-v1.0`.
6. Record the commit SHA in the score sheet, journal and video description.
7. Do not change constants without creating a new version.
