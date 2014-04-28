/*
 * Read temperature and light and display on the LCD
 *
 * For: Arduino Uno R3
 *
 * Parts:
 * 1x LCD (16x2 characters)
 * 1x 10 kΩ variable resistor
 * 1x 10 KΩ resistor
 * 1x 220 Ω resitor
 * 1x Photocell
 * 1x TMP36 temperature sensor
 */
#include <LiquidCrystal.h>

int temperaturePin = 0;
int lightPin = 1;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // Set columns and rows to use
  lcd.begin(16, 2);
  // Start on the first row
  lcd.print("Temp :      C");
}

void loop() {
  int temperatureReading = analogRead(temperaturePin);
  float temperatureInVolts = (temperatureReading / 1024.0) * 5.0;
  float temperatureInCelcius = (temperatureInVolts - 0.5) * 100;
  // Jump 6 columns
  lcd.setCursor(6, 0);
  lcd.print(temperatureInCelcius);
  
  int lightReading = analogRead(lightPin);
  // Jump to the next row
  lcd.setCursor(0, 1);
  lcd.print("Light:           ");  
  lcd.setCursor(6, 1);
  lcd.print(lightReading);
  delay(1000);
}
