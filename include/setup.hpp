#include <headers.hpp>

class Setup {
private:
  std::shared_ptr<fauxmoESP> alexa;
  Device* devices;
  int device_count;

public:
  Setup(std::shared_ptr<fauxmoESP> alexa, Device* devices, int device_count);
  static boolean connect_wifi(String ssid, String password, boolean verbose = false, int tries = 20);

  void setup_devices();
  void manual_switches();
  void handle_actions();
};