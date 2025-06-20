# Basic Line Follower Robot (LFR)

This repository contains the basic code and circuit design for a simple line follower robot. The robot follows a black line on a white surface using IR sensors and a motor driver.

---

## 🛠 Features

- Simple line-following algorithm
- Supports 2-motor differential drive
- Uses IR sensors for line detection
- Written for Arduino-based microcontrollers

---

## 🧾 Requirements

- Arduino board (Nano/Uno)
- L293D Motor Driver
- IR Sensors (2x recommended)
- Chassis with 2 DC motors
- Power source (e.g., 9V battery or 2-cell Li-ion)
- Connecting wires, breadboard or PCB

---

## 🖥 Code

To upload the code to your Arduino:

```bash
// IR sensor pins
const int irLeft = 2;
const int irRight = 3;

// Motor driver pins
const int IN1 = 5;  // Left motor
const int IN2 = 6;
const int IN3 = 9;  // Right motor
const int IN4 = 10;

// Motor speed
const int SPEED = 150;

void setup() {
  // IR sensors as input
  pinMode(irLeft, INPUT);
  pinMode(irRight, INPUT);

  // Motor pins as output
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

  digitalWtite(7, HIGH);
  digitalWtite(8, HIGH);
}

void loop() {
  int leftState = digitalRead(irLeft);
  int rightState = digitalRead(irRight);

  if (leftState == LOW && rightState == LOW) {
    // Both sensors on black - go forward
    forward();
  } else if (leftState == LOW && rightState == HIGH) {
    // Left on black - turn left
    turnLeft();
  } else if (leftState == HIGH && rightState == LOW) {
    // Right on black - turn right
    turnRight();
  } else {
    // Both on white - stop
    stopMotors();
  }
}

// Helper functions
void forward() {
  analogWrite(IN1, SPEED);
  analogWrite(IN2, 0);
  analogWrite(IN3, SPEED);
  analogWrite(IN4, 0);
}

void turnLeft() {
  analogWrite(IN1, 0);
  analogWrite(IN2, SPEED);
  analogWrite(IN3, SPEED);
  analogWrite(IN4, 0);
}

void turnRight() {
  analogWrite(IN1, SPEED);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, SPEED);
}

void stopMotors() {
  analogWrite(IN1, 0);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, 0);
}
