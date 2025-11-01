## Structure

There are examples in the examples folder.

To flash one to the device, copy/paste the code to main/main.cpp and then build/flash it.

You may or may not need to enable the Arduino setup/loop depending on the example.

## Arduino.h notes

In `sdkconfig` add the following to enable the setup/loop Arduino functions.:

```
CONFIG_AUTOSTART_ARDUINO=y
```

Or enable it with the CLI gui:

```
$ source $IDF_PATH/export.sh
# this only works if you've opeend the ESP-IDF Terminal in VS Code
$ idf.py menuconfig
# Arduino -> Auto run setup/loop at start

```
