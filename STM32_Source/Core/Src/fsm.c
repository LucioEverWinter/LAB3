/*
 * fsm.c
 *
 *  Created on: Nov 20, 2022
 *      Author: Admin
 */

#include "fsm.h"

int total_time = 0;
int counter1 = 0;
int counter2 = 0;
int num1 = 0;
int num2 = 0;
int num3 = 0;
int num4 = 0;
int tempRED = 0;
int tempYELLOW = 0;
int tempGREEN = 0;
int dis1 = 0;
int dis2 = 0;

void fsm_run() {
	switch (state) {
	case RESET:
		setTimer1(500);
		setTimer2(1000);

		tempRED = timeRED;
		tempYELLOW = timeYELLOW;
		tempGREEN = timeGREEN;

		counter1 = 0;
		counter2 = 0;

		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);

		HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_GREEN_0_GPIO_Port, LED_GREEN_0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_YELLOW_0_GPIO_Port, LED_YELLOW_0_Pin, GPIO_PIN_SET);

		state = MODE_1;
		break;
	case MODE_1:
		updateClockBuffer(dis1/10, dis1%10, dis2/10, dis2%10);

		if(timer1_flag == 1){
			counter1++;
			counter2++;

			if(counter1 <= timeRED){

				HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);

				dis1 = timeRED - counter1;
			}
			else if(counter1 <= timeRED + timeGREEN){

				HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET);

				dis1 = timeRED + timeGREEN - counter1;
			}
			else if(counter1 <= timeRED + timeYELLOW + timeGREEN){

				HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);

				dis1 = timeRED + timeYELLOW + timeGREEN - counter1;
			}
			if(counter1 >= timeRED + timeYELLOW + timeGREEN) counter1 = -1;

			if(counter2 <= timeGREEN){

				HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_YELLOW_0_GPIO_Port, LED_YELLOW_0_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_GREEN_0_GPIO_Port, LED_GREEN_0_Pin, GPIO_PIN_RESET);

				dis2 = timeGREEN - counter2;
			}
			else if(counter2 <= timeGREEN + timeYELLOW){

				HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_YELLOW_0_GPIO_Port, LED_YELLOW_0_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED_GREEN_0_GPIO_Port, LED_GREEN_0_Pin, GPIO_PIN_SET);

				dis2 = timeGREEN + timeYELLOW - counter2;
			}
			else if(counter2 <= timeRED + timeYELLOW + timeGREEN){

				HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED_YELLOW_0_GPIO_Port, LED_YELLOW_0_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED_GREEN_0_GPIO_Port, LED_GREEN_0_Pin, GPIO_PIN_SET);

				dis2 = timeRED + timeYELLOW + timeGREEN - counter2;
			}
			if(counter2 >= timeRED + timeYELLOW + timeGREEN) counter2 = -1;

			setTimer1(1000);
		}



		if (isButton1Pressed() == 1) {
			setTimer2(500);

			counter1 = 0;
			counter2 = 0;

			state = MODE_2;

			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_YELLOW_0_GPIO_Port, LED_YELLOW_0_Pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN_0_GPIO_Port, LED_GREEN_0_Pin, GPIO_PIN_SET);
		}
		break;
	case MODE_2:
		updateClockBuffer(0, 2, tempRED/10, tempRED%10);

		if (timer2_flag == 1) {
			HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
			HAL_GPIO_TogglePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin);
			setTimer2(500);
		}

		if (isButton1Pressed() == 1) {
			setTimer2(500);

			state = MODE_3;

			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_YELLOW_0_GPIO_Port, LED_YELLOW_0_Pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN_0_GPIO_Port, LED_GREEN_0_Pin, GPIO_PIN_SET);
		}

		if (isButton2Pressed() == 1) {
			setTimer2(500);
			tempRED++;
			if (tempRED >= 100) tempRED = 0;
			state = MODI_2;
		}
		break;
	case MODI_2:
		updateClockBuffer(0, 2, tempRED/10, tempRED%10);

		if (timer2_flag == 1) {
			HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
			HAL_GPIO_TogglePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin);
			setTimer2(500);
		}

		if (isButton1Pressed() == 1) {
			setTimer2(500);

			state = MODE_3;

			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_YELLOW_0_GPIO_Port, LED_YELLOW_0_Pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN_0_GPIO_Port, LED_GREEN_0_Pin, GPIO_PIN_SET);
		}

		if (isButton2Pressed() == 1) {
			setTimer2(500);
			tempRED++;
			if (tempRED >= 100) tempRED = 0;
		}

		if (isButton3Pressed() == 1) {
			timeRED = tempRED;
			state = MODE_2;
		}
		break;
	case MODE_3:
		updateClockBuffer(0, 3, tempYELLOW/10, tempYELLOW%10);

		if (timer2_flag == 1) {
			HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
			HAL_GPIO_TogglePin(LED_YELLOW_0_GPIO_Port, LED_YELLOW_0_Pin);
			setTimer2(500);
		}

		if (isButton1Pressed() == 1) {
			setTimer2(500);

			state = MODE_4;

			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_YELLOW_0_GPIO_Port, LED_YELLOW_0_Pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN_0_GPIO_Port, LED_GREEN_0_Pin, GPIO_PIN_SET);
		}

		if (isButton2Pressed() == 1) {
			setTimer2(500);
			tempYELLOW++;
			if (tempYELLOW >= 100) tempYELLOW = 0;
			state = MODI_3;
		}
		break;
	case MODI_3:
		updateClockBuffer(0, 3, tempYELLOW/10, tempYELLOW%10);

		if (timer2_flag == 1) {
			HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
			HAL_GPIO_TogglePin(LED_YELLOW_0_GPIO_Port, LED_YELLOW_0_Pin);
			setTimer2(500);
		}

		if (isButton1Pressed() == 1) {
			setTimer2(500);

			state = MODE_4;

			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_YELLOW_0_GPIO_Port, LED_YELLOW_0_Pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN_0_GPIO_Port, LED_GREEN_0_Pin, GPIO_PIN_SET);
		}

		if (isButton2Pressed() == 1) {
			setTimer2(500);
			tempYELLOW++;
			if (tempYELLOW >= 100) tempYELLOW = 0;
		}

		if (isButton3Pressed() == 1) {
			tempYELLOW = tempYELLOW;
			state = MODE_3;
		}
		break;
	case MODE_4:
		updateClockBuffer(0, 4, tempGREEN/10, tempGREEN%10);

		if (timer2_flag == 1) {
			HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
			HAL_GPIO_TogglePin(LED_GREEN_0_GPIO_Port, LED_GREEN_0_Pin);
			setTimer2(500);
		}

		if (isButton1Pressed() == 1) {
			setTimer2(500);

			state = RESET;

			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_YELLOW_0_GPIO_Port, LED_YELLOW_0_Pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN_0_GPIO_Port, LED_GREEN_0_Pin, GPIO_PIN_SET);
		}

		if (isButton2Pressed() == 1) {
			setTimer2(500);
			tempGREEN++;
			if (tempGREEN >= 100) tempGREEN = 0;
			state = MODI_4;
		}
		break;
	case MODI_4:
		updateClockBuffer(0, 4, tempGREEN/10, tempGREEN%10);

		if (timer2_flag == 1) {
			HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
			HAL_GPIO_TogglePin(LED_GREEN_0_GPIO_Port, LED_GREEN_0_Pin);
			setTimer2(500);
		}

		if (isButton1Pressed() == 1) {
			setTimer2(500);

			state = RESET;

			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_YELLOW_0_GPIO_Port, LED_YELLOW_0_Pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN_0_GPIO_Port, LED_GREEN_0_Pin, GPIO_PIN_SET);
		}

		if (isButton2Pressed() == 1) {
			setTimer2(500);
			tempGREEN++;
			if (tempGREEN >= 100) tempGREEN = 0;
		}

		if (isButton3Pressed() == 1) {
			tempGREEN = tempGREEN;
			state = MODE_4;
		}
		break;
	default:
		break;
	}
}
