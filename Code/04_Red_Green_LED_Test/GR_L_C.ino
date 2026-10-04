#include <Servo.h>

Servo myServo;

// Pin connections
const int servoPin = 9;
const int trigPin = 10;
const int echoPin = 11;

const int greenLED = 6;
const int redLED = 7;

// Occupied threshold
const int occupiedDistance = 20;

void setup()
{
  Serial.begin(9600);

  myServo.attach(servoPin);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  // Initially both LEDs OFF
  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, LOW);

  myServo.write(0);
  delay(1000);
}

void loop()
{
  for (int angle = 0; angle <= 180; angle += 45)
  {
    // Move servo
    myServo.write(angle);
    delay(1000);

    // Ultrasonic measurement
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);

    digitalWrite(trigPin, LOW);

    long duration = pulseIn(echoPin, HIGH, 30000);

    if (duration > 0)
    {
      float distance = duration * 0.0343 / 2;

      Serial.print("Angle: ");
      Serial.print(angle);
      Serial.print("°   Distance: ");
      Serial.print(distance);
      Serial.print(" cm   ");

      // Parking status
      if (distance <= occupiedDistance)
      {
        Serial.println("OCCUPIED");

        // Red ON, Green OFF
        digitalWrite(greenLED, LOW);
        digitalWrite(redLED, HIGH);
      }
      else
      {
        Serial.println("AVAILABLE");

        // Green ON, Red OFF
        digitalWrite(greenLED, HIGH);
        digitalWrite(redLED, LOW);
      }
    }

    delay(300);
  }
}