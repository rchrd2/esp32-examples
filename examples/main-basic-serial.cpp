#include "Arduino.h"

void setup(){
  // Initialize Serial (USB Serial/JTAG on ESP32-C3)
  Serial.begin(115200);
  // For ESP32-C3 native USB, don't use blocking while(!Serial)
  // Give USB time to initialize
  delay(2000);

  // Try multiple ways to output
  Serial.println("=== Setup complete! ===");
  Serial.println("Starting loop...");
  Serial.flush();

  // Also try printf to see if USB console works
  printf("ESP-IDF printf test\n");
}

void loop(){
    Serial.println("loop");
    Serial.flush();
    printf("ESP-IDF printf in loop\n");
    delay(1000);
}

// #include "Arduino.h"

// #ifdef ARDUINO_ARCH_ESP32
// #include "esp32-hal-log.h"
// #endif

// // extern "C" void app_main()
// // {
// //     initArduino();
// //     pinMode(8, OUTPUT);
// //     digitalWrite(8, HIGH);
// //     while (true) {
// //         digitalWrite(8, HIGH);
// //         delay(100);
// //         digitalWrite(8, LOW);
// //         delay(100);
// //     }
// // }




// // Button pin - GPIO9 is typically the BOOT button on ESP32-C3 boards
// const int BUTTON_PIN = 9;
// // LED pin
// const int LED_PIN = 8;

// // the setup function runs once when you press reset or power the board
// void setup() {
//   Serial.begin(115200);
//   while (!Serial) {
//     ; // wait for serial port to connect
//   }

//   // Initialize LED pin as output
//   pinMode(LED_PIN, OUTPUT);
//   pinMode(7, OUTPUT);  // Keep your buzzer pin

//   // Initialize button pin as input with internal pull-up resistor
//   // BOOT button is active LOW (pressed = LOW, not pressed = HIGH)
//   pinMode(BUTTON_PIN, INPUT_PULLUP);

//   Serial.println("ESP32-C3 Button Test");
//   Serial.println("Press the BOOT button (GPIO9) to turn on the LED");
// }

// // the loop function runs over and over again forever
// void loop() {
//   // Read button state (LOW when pressed, HIGH when not pressed due to pull-up)
//   int buttonState = digitalRead(BUTTON_PIN);

//   // Update LED based on button state
//   if (buttonState == LOW) {
//     // Button is pressed - turn on LED
//     digitalWrite(LED_PIN, HIGH);
//   } else {
//     // Button is released - turn off LED
//     digitalWrite(LED_PIN, LOW);
//   }

//   delay(100);
// }
