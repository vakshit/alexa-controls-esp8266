#include <setup.hpp>
#include <utils.hpp>

std::shared_ptr<fauxmoESP> alexa = std::make_shared<fauxmoESP>();
short counter = 0;
boolean wifi_connected = false;
Device devices[] = {Device{"test light", 4}, Device{"test fan", 5}};

void setup() {
  // initiaie connection
  Serial.begin(BAUD_RATE);

  // initialize the setup class
  Setup setup = Setup(alexa, devices, 2);

  // connect to WiFi
  wifi_connected = Setup::connect_wifi("ssid", "password");
  if (wifi_connected) {
    // setup devices and their pinModes
    setup.setup_devices();

    // handle actions
    setup.handle_actions();
  }
}

void loop() {
  if (wifi_connected) {
    alexa->handle();
  } else {
    if (counter < 10) {
      blink_once(500);
      counter++;
    }
  }
  if (counter >= 10)
    ESP.deepSleep(0);
}