#include "Arduino.h"

// Button pin - GPIO9 is typically the BOOT button on ESP32-C3 boards
const int BUTTON_PIN = 9;
// LED pin
const int LED_PIN = 8;


void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}


void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW) {
    // Button is pressed - turn on LED
    digitalWrite(LED_PIN, HIGH);
  } else {
    // Button is released - turn off LED
    digitalWrite(LED_PIN, LOW);
  }

  delay(100);
}
