#include <Arduino.h>
#include <fauxmoESP.h>
#include <wifi.hpp>

fauxmoESP fauxmo;

void setup() {

    Serial.begin(115200);
    connectToWiFi("JioFiber-4", "uzumymwalks");
    fauxmo.addDevice("test light");

    fauxmo.setPort(80); // required for gen3 devices
    fauxmo.enable(true);

    fauxmo.onSetState([](unsigned char device_id, const char * device_name, bool state, unsigned char value) {
        Serial.printf("[MAIN] Device #%d (%s) state: %s value: %d\n", device_id, device_name, state ? "ON" : "OFF", value);
    });

}

void loop() {
    fauxmo.handle();
}