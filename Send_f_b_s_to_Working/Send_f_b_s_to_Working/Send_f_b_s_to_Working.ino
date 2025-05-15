#include <SoftwareSerial.h>

// Bluetooth pins
SoftwareSerial btSerial(10, 11); // RX, TX

// Drive motor
#define IN1 5
#define IN2 6

// Steering motor
#define IN3 2
#define IN4 3

bool steeringLeft = false;
bool steeringRight = false;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
  btSerial.begin(9600);
}

void loop() {
  if (btSerial.available()) {
    char command = btSerial.read();
    Serial.print("Received: ");
    Serial.println(command);

    switch (command) {
      case 'f': // Forward
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        break;

      case 'b': // Backward
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        break;

      case 's': // Stop
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        break;

      case 'l': // Toggle left
        if (!steeringLeft) {
          digitalWrite(IN3, HIGH);
          digitalWrite(IN4, LOW);
          steeringLeft = true;
          steeringRight = false; // cancel opposite if active
        } else {
          digitalWrite(IN3, LOW);
          digitalWrite(IN4, LOW);
          steeringLeft = false;
        }
        break;

      case 'r': // Toggle right
        if (!steeringRight) {
          digitalWrite(IN3, LOW);
          digitalWrite(IN4, HIGH);
          steeringRight = true;
          steeringLeft = false;
        } else {
          digitalWrite(IN3, LOW);
          digitalWrite(IN4, LOW);
          steeringRight = false;
        }
        break;
    }
  }
}