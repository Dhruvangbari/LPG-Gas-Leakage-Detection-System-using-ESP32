/*
 LPG Gas Leakage Detection System using ESP32
 Components Used:
 - ESP32 Development Board
 - MQ-2 Gas Sensor
 - Buzzer
 - Red LED (Gas Detected)
 - Green LED (Safe Condition)
 - 16x2 LCD Display (Parallel Mode)
*/

#include <LiquidCrystal.h>

LiquidCrystal lcd(23, 22, 21, 19, 18, 5);

const int mq2Pin = 34;
const int buzzerPin = 25;
const int redLed = 26;
const int greenLed = 27;

int gasValue = 0;
int threshold = 1800;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);

  lcd.begin(16, 2);
  lcd.print("LPG GAS SYSTEM");
  lcd.setCursor(0, 1);
  lcd.print("ESP32 STARTING");
  delay(2000);
  lcd.clear();
}

void loop() {
  gasValue = analogRead(mq2Pin);

  lcd.setCursor(0, 0);
  lcd.print("Gas Level: ");
  lcd.print(gasValue);
  lcd.print(" ");

  if (gasValue > threshold) {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(buzzerPin, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("!! GAS LEAK !! ");
  } else {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    digitalWrite(buzzerPin, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Status: SAFE ");
  }

  delay(1000);
}
