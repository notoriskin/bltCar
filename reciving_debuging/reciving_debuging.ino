#include <SoftwareSerial.h>
SoftwareSerial btSerial(10, 11); // RX, TX

// Drive motor
#define DRIVE_IN1 5
#define DRIVE_IN2 6

// Steering motor
#define STEER_IN1 2
#define STEER_IN2 3

bool driveForward = false;
bool driveBackward = false;
bool steeringLeft = false;
bool steeringRight = false;

void setup() {
  pinMode(DRIVE_IN1, OUTPUT);
  pinMode(DRIVE_IN2, OUTPUT);
  pinMode(STEER_IN1, OUTPUT);
  pinMode(STEER_IN2, OUTPUT);

  Serial.begin(9600);
  btSerial.begin(9600);
}

void loop() {
  if (btSerial.available()) {
    byte incoming = btSerial.read();
    Serial.print("Byte: ");
    Serial.println(incoming);

    switch (incoming) {
      case 1: // Toggle forward
        if (!driveForward) {
          digitalWrite(DRIVE_IN1, HIGH);
          digitalWrite(DRIVE_IN2, LOW);
          driveForward = true;
          driveBackward = false; // cancel backward
        } else {
          digitalWrite(DRIVE_IN1, LOW);
          digitalWrite(DRIVE_IN2, LOW);
          driveForward = false;
        }
        break;

      case 2: // Toggle backward
        if (!driveBackward) {
          digitalWrite(DRIVE_IN1, LOW);
          digitalWrite(DRIVE_IN2, HIGH);
          driveBackward = true;
          driveForward = false; // cancel forward
        } else {
          digitalWrite(DRIVE_IN1, LOW);
          digitalWrite(DRIVE_IN2, LOW);
          driveBackward = false;
        }
        break;

      case 4: // Toggle left
        if (!steeringLeft) {
          digitalWrite(STEER_IN1, HIGH);
          digitalWrite(STEER_IN2, LOW);
          steeringLeft = true;
          steeringRight = false;
        } else {
          digitalWrite(STEER_IN1, LOW);
          digitalWrite(STEER_IN2, LOW);
          steeringLeft = false;
        }
        break;

      case 8: // Toggle right
        if (!steeringRight) {
          digitalWrite(STEER_IN1, LOW);
          digitalWrite(STEER_IN2, HIGH);
          steeringRight = true;
          steeringLeft = false;
        } else {
          digitalWrite(STEER_IN1, LOW);
          digitalWrite(STEER_IN2, LOW);
          steeringRight = false;
        }
        break;
    }
  }
}