#include "Arduino.h"

extern "C" void app_main()
{
    initArduino();
    pinMode(8, OUTPUT);
    digitalWrite(8, HIGH);
    while (true) {
        digitalWrite(8, HIGH);
        delay(100);
        digitalWrite(8, LOW);
        delay(100);
    }
}