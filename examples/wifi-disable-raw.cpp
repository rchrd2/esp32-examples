#include <esp_wifi.h>
#include <cstdio>

void disableWifi() {
  // Properly disable WiFi to save power
  printf("Disabling WiFi...\n");
  esp_err_t ret;

  // Stop WiFi if it's running
  printf("Calling esp_wifi_stop()...\n");
  ret = esp_wifi_stop();
  if (ret == ESP_OK) {
    printf("WiFi stopped successfully\n");
  } else if (ret == ESP_ERR_WIFI_NOT_INIT) {
    printf("WiFi was not initialized (this is OK)\n");
  } else {
    printf("Error stopping WiFi: %d (0x%x)\n", ret, ret);
    // This is non-fatal, continue anyway
  }

  // Deinitialize WiFi stack
  printf("Calling esp_wifi_deinit()...\n");
  ret = esp_wifi_deinit();
  if (ret == ESP_OK) {
    printf("WiFi deinitialized successfully\n");
  } else if (ret == ESP_ERR_WIFI_NOT_INIT) {
    printf("WiFi was not initialized (this is OK)\n");
  } else {
    printf("Error deinitializing WiFi: %d (0x%x)\n", ret, ret);
    // This is non-fatal, continue anyway
  }

  printf("WiFi disable complete\n");
}

void disableBluetooth() {
#ifdef CONFIG_BT_ENABLED
  printf("WARNING: Bluetooth is enabled at compile time!\n");
  printf("To disable Bluetooth and save power, run:\n");
  printf("  idf.py menuconfig\n");
  printf("Then navigate to: Component config -> Bluetooth\n");
  printf("Uncheck 'Bluetooth' to disable it.\n");
  printf("Alternatively, edit sdkconfig and ensure:\n");
  printf("  # CONFIG_BT_ENABLED is not set\n");
  printf("\n");
#else
  // Bluetooth is already disabled at compile time - nothing to do
  printf("Bluetooth is disabled at compile time (good for power savings)\n");
#endif
}

extern "C" void app_main()
{
  disableWifi();
  disableBluetooth();
}
