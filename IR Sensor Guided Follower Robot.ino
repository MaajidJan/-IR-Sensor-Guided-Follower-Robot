#include <Servo.h>
#include <AFMotor.h>
#include <NewPing.h>

Servo s1;
AF_DCMotor Motor1(1);  // Motor connected to M1
AF_DCMotor Motor2(2);  // Motor connected to M2
AF_DCMotor Motor3(3);  // Motor connected to M3
AF_DCMotor Motor4(4);  // Motor connected to M4

int RS = A3;           // Right Sensor
int LS = A4;           // LEFT  Sensor

int echo = A0;         // Echo Pin for ultrasonic sensor
int trig = A1;         // Trig Pin for ultrasonic sensor

int RSV = 0;           // Right Sensor Value
int LSV = 0;           // Left Sensor Value
int pos = 90;          // Initial position of the servo

NewPing sonar(echo, trig, 200); // Ultrasonic sensor object

void setup() {
  pinMode(RS, INPUT);
  pinMode(LS, INPUT);
  s1.attach(10); // Attach the servo to pin 10
}

void loop() {
  RSV = digitalRead(RS); // Read the state of the right sensor
  LSV = digitalRead(LS); // Read the state of the left sensor

  // Move the servo based on sensor inputs
  if (RSV == LOW && pos > 0) {
    pos--;
    s1.write(pos);
    delay(100);
    // Move motors for a right turn
    Motor1.setSpeed(150);
    Motor2.setSpeed(200);
    Motor3.setSpeed(200);
    Motor4.setSpeed(150);
    Motor1.run(BACKWARD);
    Motor2.run(FORWARD);
    Motor3.run(FORWARD);
    Motor4.run(BACKWARD);
  } else if (LSV == LOW && pos < 180) {
    pos++;
    s1.write(pos);
    delay(100);
    // Move motors for a left turn
    Motor1.setSpeed(200);
    Motor2.setSpeed(150);
    Motor3.setSpeed(150);
    Motor4.setSpeed(200);
    Motor1.run(FORWARD);
    Motor2.run(BACKWARD);
    Motor3.run(BACKWARD);
    Motor4.run(FORWARD);
  } else if (LSV == LOW && RSV == LOW) {
    // Both sensors are LOW, stop the servo
    s1.write(pos);
    // Move all motors forward
    Motor1.setSpeed(200);
    Motor2.setSpeed(200);
    Motor3.setSpeed(200);
    Motor4.setSpeed(200);
    Motor1.run(FORWARD);
    Motor2.run(FORWARD);
    Motor3.run(FORWARD);
    Motor4.run(FORWARD);
  }

  // Check the distance from the ultrasonic sensor
  int distance = sonar.ping_cm();

  if (distance >= 1 && distance <= 3) {
    // Distance between 1 to 3 cm, move all motors backward
    Motor1.setSpeed(100);
    Motor2.setSpeed(100);
    Motor3.setSpeed(100);
    Motor4.setSpeed(100);
    Motor1.run(BACKWARD);
    Motor2.run(BACKWARD);
    Motor3.run(BACKWARD);
    Motor4.run(BACKWARD);
  }
}
