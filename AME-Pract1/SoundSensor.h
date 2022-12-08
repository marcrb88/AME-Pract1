#include "mbed.h"
#include <cstdint>

class SoundSensor {
public:
  SoundSensor(AnalogIn pin);
  float read();
  float calculate_voltage(float counts);
  float calculate_sensitivity ();
  float calculate_SPL (float vOut);

private:
  AnalogIn _soundSensor;
  float _counts;
};