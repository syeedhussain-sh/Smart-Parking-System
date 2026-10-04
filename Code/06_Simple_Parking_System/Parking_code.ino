#include <Servo.h>

Servo myServo;

const int servoPin = 9;
const int trigPin = 10;
const int echoPin = 11;

const int occupiedDistance = 20;

void setup()
{
  Serial.begin(9600);

  myServo.attach(9);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  myServo.write(0);
  delay(1000);
}

void loop()
{
  for (int angle = 0; angle <= 180; angle += 45)
  {
    myServo.write(angle);

    delay(700);

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
      Serial.print("°  Distance: ");
      Serial.print(distance);
      Serial.print(" cm  ");

      if (distance <= occupiedDistance)
      {
        Serial.println("OCCUPIED");
      }
      else
      {
        Serial.println("AVAILABLE");
      }
    }

    delay(300);
  }
}