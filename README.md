## Description
The Automated Spice Recipe make uses an Arduino Uno which measures the weight of different ingredients using a load cell and HX711 load cell amplifier according to a pre-programmed recipe and releases them to a container.
Control is done via a [Blynk](https://blynk.io/) app which communicates with the Arduino using an ESP8266 WiFi module. Product also sends feedback to a configured cellular device via a GSM SIM900A module.

Simply select recipe from Blynk and accordingly the valves of the containers with the ingredients will open. An sms is sent to the configured cellular device to provide feedback on how much quantity of ingredients was actually released.

Replace `xxx` in SpiceRecipe.ino with the desired quantity of a ingredient (in grams).

Error in quantity released is <2% (after calibration).

Code can be modified to provide multiple ingredients and recipes.

Click to watch [video](https://www.instagram.com/p/BtGgWqtDdTo/?utm_source=ig_web_copy_link)
