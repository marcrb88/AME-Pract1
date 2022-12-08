#include "SoundSensor.h"
#include "mbed.h"
#include <cstdint>

const float MICRO_SENSITIVITY = 50;
const float VREF = 5;

uint16_t _counts;

SoundSensor::SoundSensor(AnalogIn soundSensor) : _soundSensor(soundSensor) {
 _soundSensor = soundSensor;
}

float SoundSensor::read() {
    _counts = _soundSensor.read();

    return _counts;
}

float SoundSensor::calculate_voltage(float counts) {
    return VREF * (counts);
}

float SoundSensor::calculate_sensitivity () {
    return pow(10, MICRO_SENSITIVITY/20) / 100;
}

float SoundSensor::calculate_SPL (float vOut) {
    return vOut > 0? (94 + (20 * log10(vOut / calculate_sensitivity()))) : 0;
}
