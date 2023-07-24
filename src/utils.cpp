#include <utils.hpp>
void blink_once(int delay_time) {
  digitalWrite(INDICATOR, LOW);
  delay(delay_time);
  digitalWrite(INDICATOR, HIGH);
  delay(delay_time);
}