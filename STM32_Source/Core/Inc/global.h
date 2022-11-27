/*
 * global.h
 *
 *  Created on: Nov 20, 2022
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"

#define RESET 0
#define MODE_1 1
#define MODE_2 2
#define MODI_2 20
#define MODE_3 3
#define MODI_3 30
#define MODE_4 4
#define MODI_4 40

extern int state;

extern int time7SEG;
extern int time7SEG0;

extern int timeRED;
extern int timeGREEN;
extern int timeYELLOW;

extern int led_buffer[4];

void updateClockBuffer(int num0, int num1, int num2, int num3);
void update7SEG(int index);

#endif /* INC_GLOBAL_H_ */
