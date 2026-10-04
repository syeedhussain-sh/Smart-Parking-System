#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

Servo myServo;
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pin definitions
const int servoPin = 9;
const int trigPin = 10;
const int echoPin = 11;

const int greenLED = 6;
const int redLED = 7;
const int buzzer = 8;

// Parking threshold
const int occupiedDistance = 20;

// LED blinking
unsigned long previousMillis = 0;
const long blinkInterval = 500;

bool ledState = false;
bool occupied = false;

void setup()
{
  Serial.begin(9600);

  myServo.attach(servoPin);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("SMART PARKING");

  lcd.setCursor(0, 1);
  lcd.print("SYSTEM READY");

  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, LOW);
  digitalWrite(buzzer, LOW);

  myServo.write(0);

  delay(2000);
}

void loop()
{
  for (int angle = 0; angle <= 180; angle += 45)
  {
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
      Serial.print("   Distance: ");
      Serial.print(distance);
      Serial.print(" cm   ");

      if (distance <= occupiedDistance)
      {
        occupied = true;

        Serial.println("FULL");

        lcd.clear();

        lcd.setCursor(0, 0);
        lcd.print("SMART PARKING");

        lcd.setCursor(0, 1);
        lcd.print("FULL");

        // Short buzzer alert
        digitalWrite(buzzer, HIGH);
        delay(150);
        digitalWrite(buzzer, LOW);
      }
      else
      {
        occupied = false;

        Serial.println("FREE");

        lcd.clear();

        lcd.setCursor(0, 0);
        lcd.print("SMART PARKING");

        lcd.setCursor(0, 1);
        lcd.print("FREE");

        // Buzzer OFF
        digitalWrite(buzzer, LOW);
      }
    }
    else
    {
      occupied = false;

      Serial.println("NO ECHO");

      lcd.clear();

      lcd.setCursor(0, 0);
      lcd.print("SMART PARKING");

      lcd.setCursor(0, 1);
      lcd.print("NO ECHO");

      digitalWrite(buzzer, LOW);
    }

    // LED blinking
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= blinkInterval)
    {
      previousMillis = currentMillis;

      ledState = !ledState;

      if (occupied)
      {
        digitalWrite(redLED, ledState);
        digitalWrite(greenLED, LOW);
      }
      else
      {
        digitalWrite(greenLED, ledState);
        digitalWrite(redLED, LOW);
      }
    }

    delay(300);
  }
}