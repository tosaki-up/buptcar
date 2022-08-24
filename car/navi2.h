#include "pins.h"
#include "motion.h"

const int n_navi = 5;
int hw[5] = {24, 25, 26, 27, 28};

void pinout_init_navigation()
{
    for (auto i = 0; i < n_navi; i++)
    {
        pinMode(hw[i], INPUT);
    }
}

int sensor[5], turn_rate = 0;

void navi_loop()
{
    turn_rate = 0;

    for (auto i = 0; i < n_navi; i++)
    {
        sensor[i] = digitalRead(hw[i]);
        turn_rate += -85 * sensor[i] * (i - 2);

        Serial.print(sensor[i]);
        Serial.print(" ");
    }
    Serial.println(turn_rate);
    turn(turn_rate);
}