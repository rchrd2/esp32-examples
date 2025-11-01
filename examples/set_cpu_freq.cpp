/*
 *  ESP32
 *  Manage CPU Frequences
 *  by Mischianti Renzo <https://mischianti.org>
 *
 *  https://mischianti.org
 *
 * You may copy, alter and reuse this code in any way you like, but please leave
 * reference to www.mischianti.org in your comments if you redistribute this code.
 */

#include "Arduino.h"
#include <inttypes.h>

void setup()
{
    delay(2000);

    printf("CPU Freq: %" PRIu32 " MHz\n", getCpuFrequencyMhz());

    setCpuFrequencyMhz(80);

    printf("CPU Freq: %" PRIu32 " MHz\n", getCpuFrequencyMhz());

    delay(1000);


    setCpuFrequencyMhz(10);

    printf("CPU Freq: %" PRIu32 " MHz\n", getCpuFrequencyMhz());
}

void loop()
{

}


/*
By setting

1
setCpuFrequencyMhz(160);
is 45.9mA, by setting

1
setCpuFrequencyMhz(80);
the power become 33.2mA, and with

1
setCpuFrequencyMhz(40);
è 19.88mA, then I try to set

1
setCpuFrequencyMhz(20);
the power become 15.43mA with

1
setCpuFrequencyMhz(10);
and the power becomes 13.19mA.

https://mischianti.org/esp32-practical-power-saving-manage-wifi-and-cpu-1/

*/