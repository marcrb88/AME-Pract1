#include "mbed.h"

float calculate_voltage(uint16_t counts) {
    return 3.3 * (counts/65535)/1023;
}
// main() runs in its own thread in the OS
int main()
{
    AnalogIn read_data (A0);
    while (true) {
        uint16_t counts = read_data.read_u16();
        printf("Counts %d", counts);
        printf ("Voltatge: %f\n",calculate_voltage(counts));
        ThisThread::sleep_for(1000ms);
    }
}

