#include "mbed.h"
#include "Grove_LCD_RGB_Backlight.h"
#include <string>
#include <cstring>
#include <SoundSensor.h>

float spl;
Grove_LCD_RGB_Backlight lcd(D14,D15);

SoundSensor ss (A0);
DigitalOut led (A1);
Thread thread;

void determinate_noise () {
    while(true){
        led = !led;
        if (spl > 60){
            lcd.setRGB(255, 0, 0);
            ThisThread::sleep_for(500ms);
        }else{
            lcd.setRGB(0, 255, 0);
            ThisThread::sleep_for(1000ms);
        }
    }
}

int main()
{
    float counts, vOut, mean, add;
    while (true) {
        mean = 0;
        add = 0;
        counts = ss.read();
        for (int i = 0; i < 10; i++)
           add += counts;
        mean = add / 10;

        printf("mean: %f ", mean);
        vOut = ss.calculate_voltage(mean);
        printf("Voltatge: %f ", vOut);
        spl = ss.calculate_SPL(vOut);
        printf ("SPL: %f\n", spl);

        thread.start(determinate_noise);

        string message = "SPL: " + std::to_string(spl) + "db";
        char output [message.length() + 1];
        strcpy(output, message.c_str());
        lcd.clear();
        lcd.print(output);

        ThisThread::sleep_for(1000ms);
    }
}
