#include <PulseSensorPlayground.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Pulse sensor
const int pulsePin = A0;
PulseSensorPlayground pulseSensor;

// LED pins
const int redLED = 2;     // Stressed
const int whiteLED = 4;   // Neutral
const int yellowLED = 5;  // Calm
const int greenLED = 6;   // Happy

// LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);

  pinMode(redLED, OUTPUT);
  pinMode(whiteLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  lcd.init();
  lcd.backlight();

  pulseSensor.analogInput(pulsePin);
  pulseSensor.setThreshold(550);

  if (pulseSensor.begin()) {
    lcd.print("Pulse Sensor OK");
  } else {
    lcd.print("Sensor Error!");
    while (true); // Stop on error
  }

  delay(2000);
  lcd.clear();
}

void loop() {
  int bpm = pulseSensor.getBeatsPerMinute();
  bool isBeat = pulseSensor.sawStartOfBeat();

  if (isBeat) {
    lcd.clear();
    displayMoodAndTip(bpm);
    delay(1000);
  }
}

void displayMoodAndTip(int bpm) {
  digitalWrite(redLED, LOW);
  digitalWrite(whiteLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);

  if (bpm < 60) {
    lcd.setCursor(0, 0);
    lcd.print("Mood: Calm     ");
    lcd.setCursor(0, 1);
    lcd.print("Breathe & relax");
    digitalWrite(yellowLED, HIGH);
  } 
  else if (bpm >= 60 && bpm <= 85) {
    lcd.setCursor(0, 0);
    lcd.print("Mood: Normal ");
    lcd.setCursor(0, 1);
    lcd.print("Tip: Smile!! ");
    digitalWrite(whiteLED, HIGH);
  } 
  else if (bpm > 85 && bpm <= 110) {
    lcd.setCursor(0, 0);
    lcd.print("Mood: Happy    ");
    lcd.setCursor(0, 1);
    lcd.print("Tip: Cheers!! ");
    digitalWrite(greenLED, HIGH);
  } 
  else {
    lcd.setCursor(0, 0);
    lcd.print("Mood: Stressed ");
    lcd.setCursor(0, 1);
    lcd.print("Tip: Rest  ");
    digitalWrite(redLED, HIGH);
  }
}