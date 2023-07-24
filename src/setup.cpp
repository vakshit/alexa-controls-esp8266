#include <setup.hpp>

Setup::Setup(std::shared_ptr<fauxmoESP> alexa, Device* devices, int device_count) {
  this->alexa = alexa;
  this->devices = devices;
  this->device_count = device_count;
};

boolean Setup::connect_wifi(String ssid, String password, boolean verbose, int tries) {
  WiFi.begin(ssid, password);
  int retries = 0;
  while ((WiFi.status() != WL_CONNECTED) && (retries < tries)) {
    retries++;
    delay(500);
    if (verbose)
      Serial.print(".");
  }

  if (WiFi.status() == WL_CONNECTED) {
    if (verbose)
      Serial.println(F("WiFi connected!"));
    Serial.printf("IP address: %s", WiFi.localIP().toString().c_str());
    return true;
  } else {
    Serial.println(F("WiFi connection FAILED"));
    return false;
  }
}

void Setup::manual_switches() {
  for (int i = 0; i < device_count; i++) {
    pinMode(devices[i].pin, OUTPUT);
    digitalWrite(devices[i].pin, LOW);
  }
}

void Setup::setup_devices() {
  pinMode(INDICATOR, OUTPUT);
  digitalWrite(INDICATOR, HIGH);
  for (int i = 0; i < device_count; i++) {
    pinMode(devices[i].pin, OUTPUT);
    digitalWrite(devices[i].pin, LOW);
    alexa->addDevice(devices[i].name.c_str());
  }

  alexa->setPort(80);  // required for gen3 devices
  alexa->enable(true);
}

void Setup::handle_actions() {
  int modes[] = {HIGH, LOW};
  alexa->onSetState([this, modes](unsigned char device_id, const char* device_name, bool state, unsigned char value) {
    // Serial.printf("[MAIN] Device #%d (%s) state: %s value: %d\n", device_id, device_name, state ? "ON" : "OFF", value);
    int device_index = device_id;
    int pin = this->devices[device_index].pin;
    digitalWrite(pin, modes[state]);
  });
}