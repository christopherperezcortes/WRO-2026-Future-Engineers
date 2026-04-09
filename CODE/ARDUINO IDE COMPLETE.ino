#include <Wire.h>
#include "HUSKYLENS.h"
#include <Servo.h>

HUSKYLENS huskylens;
Servo direccion;

// MOTOR
#define IN1 5
#define IN2 6
#define ENA 3

// ULTRASONIC
#define TRIG_F 10
#define ECHO_F 11
#define TRIG_L 12
#define ECHO_L 13
#define TRIG_R A0
#define ECHO_R A1

// TURNS SENSOR
#define SENSOR_VUELTA 2
volatile int vueltas = 0;
unsigned long ultimaVuelta = 0;

// SERVO POSITIONS
#define CENTRO 90
#define IZQUIERDA 120
#define DERECHA 60

int velocidad = 140;

// Control
unsigned long tiempoColor = 0;
bool evitandoColor = false;

// INTERRUPTION
void contarVuelta() {
  if (millis() - ultimaVuelta > 800) {
    vueltas++;
    ultimaVuelta = millis();
  }
}

// DISTANCE
long medirDistancia(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duracion = pulseIn(echo, HIGH, 25000);

  if (duracion == 0) return 100;

  long distancia = duracion * 0.034 / 2;
  return distancia;
}

// ENGINE
void avanzar(int vel) {
  analogWrite(ENA, vel);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void detener() {
  analogWrite(ENA, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

// SETUP
void setup() {
  Serial.begin(9600);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  pinMode(TRIG_F, OUTPUT);
  pinMode(ECHO_F, INPUT);
  pinMode(TRIG_L, OUTPUT);
  pinMode(ECHO_L, INPUT);
  pinMode(TRIG_R, OUTPUT);
  pinMode(ECHO_R, INPUT);

  pinMode(SENSOR_VUELTA, INPUT);

  attachInterrupt(digitalPinToInterrupt(SENSOR_VUELTA), contarVuelta, RISING);

  direccion.attach(9);
  direccion.write(CENTRO);

  Wire.begin();

  while (!huskylens.begin(Wire)) {
    Serial.println("Error HuskyLens");
    delay(100);
  }

  Serial.println("Sistema listo");
}

// LOOP
void loop() {

  if (vueltas >= 3) {
    detener();
    direccion.write(CENTRO);
    while (1);
  }

  long distF = medirDistancia(TRIG_F, ECHO_F);
  long distL = medirDistancia(TRIG_L, ECHO_L);
  long distR = medirDistancia(TRIG_R, ECHO_R);

  if (distF < 18) {
    velocidad = 110;
  } else if (distF < 30) {
    velocidad = 130;
  } else {
    velocidad = 150;
  }

  int diferencia = distL - distR;

  if (abs(diferencia) > 5) {
    if (diferencia > 0) {
      direccion.write(80);
    } else {
      direccion.write(100);
    }
    evitandoColor = false;
  }

  else if (distL < 10) {
    direccion.write(DERECHA);
    evitandoColor = false;
  }
  else if (distR < 10) {
    direccion.write(IZQUIERDA);
    evitandoColor = false;
  }

  else if (distF < 15) {

    if (distR > distL) {
      direccion.write(DERECHA);
    } else {
      direccion.write(IZQUIERDA);
    }

    evitandoColor = false;
  }
    
  // HUSKYLENS
  else {
    if (!evitandoColor && huskylens.request()) {
      if (huskylens.available()) {

        int bloques = huskylens.available();

        int mejorID = 0;
        int mejorArea = 0;
        int mejorX = 0;
        int mejorY = 0;

        for (int i = 0; i < bloques; i++) {
          HUSKYLENSResult r = huskylens.read();

          int area = r.width * r.height;

          // ===== SERIAL OF EVERYONE =====
          Serial.print("ID: ");
          Serial.print(r.ID);
          Serial.print(" | X: ");
          Serial.print(r.xCenter);
          Serial.print(" | Y: ");
          Serial.print(r.yCenter);
          Serial.print(" | Area: ");
          Serial.println(area);
          // ===========================

          if (area > mejorArea) {
            mejorArea = area;
            mejorID = r.ID;
            mejorX = r.xCenter;
            mejorY = r.yCenter;
          }
        }

        // ===== SERIAL DEL OBJETIVO =====
        Serial.print(">>> OBJETIVO: ID ");
        Serial.print(mejorID);
        Serial.print(" | X: ");
        Serial.print(mejorX);
        Serial.print(" | Y: ");
        Serial.println(mejorY);
        // =================================

        if (mejorID == 1) { // RED
          direccion.write(DERECHA);
          evitandoColor = true;
          tiempoColor = millis();
        }

        if (mejorID == 2) { // GREEN
          direccion.write(IZQUIERDA);
          evitandoColor = true;
          tiempoColor = millis();
        }
      }
    }

    if (evitandoColor) {
      if (millis() - tiempoColor > 300) {
        evitandoColor = false;
      }
    } else {
      direccion.write(CENTRO);
    }
  }

  avanzar(velocidad);
  delay(25);
}
