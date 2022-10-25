#include "mbed.h"
#include "Grove_LCD_RGB_Backlight.h"

float calculate_voltage(float counts) {
    return 5 * (counts);
}

float calculate_SPL (float vOut) {
    return (94 + (20 * log(vOut / 3.16)));
}

Grove_LCD_RGB_Backlight lcd(D14,D15);
// main() runs in its own thread in the OS
int main()
{
    //TODO calculate_sensitivity()
    float counts, vOut, spl, mean, add;
    char message [] =  {'P','e','t','i','t'};
    AnalogIn read_data (A0);
    AnalogOut led (A1);

    while (true) {
        counts = read_data.read();
        printf("Counts %f ", counts);
        for (int i = 0; i < 50; i++)
           add += counts;

        mean = add / 50;
        vOut = calculate_voltage(mean);
        printf("Voltatge: %f ", vOut);
        spl = calculate_SPL(vOut);
        printf ("SPL: %f\n", spl);

        lcd.setRGB(255, 255, 255);
        lcd.print(message);

        
        

        ThisThread::sleep_for(1000ms);
    }
}

