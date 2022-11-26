/*
 * fsm.c
 *
 *  Created on: Nov 20, 2022
 *      Author: Admin
 */

#include "fsm.h"

int total_time = 0;
int light1_counter = 0;
int light2_counter = 0;
int num1 = 0;
int num2 = 0;
int num3 = 0;
int num4 = 0;
int tempRED = 0;
int tempYELLOW = 0;
int tempGREEN = 0;

void fsm_run() {
	switch (state) {
	case RESET:
		setTimer1(30);
		setTimer2(40);

		tempRED = timeRED;
		tempGREEN = timeGREEN;
		tempYELLOW = timeYELLOW;

		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);

		HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_GREEN_0_GPIO_Port, LED_GREEN_0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_YELLOW_0_GPIO_Port, LED_YELLOW_0_Pin, GPIO_PIN_SET);

		light1_counter = 0;
		light2_counter = 0;

		state = MODE_1;
		break;
	case MODE_1:
		total_time = timeRED + timeGREEN + timeYELLOW;
		if (light1_counter == 0) light1_counter = total_time;
		if (light2_counter == 0) light2_counter = total_time;

		if (timeRED < light1_counter && light1_counter <= total_time) {
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
			num1 = light1_counter - timeRED;
		}
		else if (timeYELLOW < light1_counter && light1_counter <= timeRED) {
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
			num1 = light1_counter - timeYELLOW;
		}
		else if (0 < light1_counter && light1_counter <= timeYELLOW) {
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_RESET);
			num1 = light1_counter;
		}

		if (timeRED + timeYELLOW < light2_counter && light2_counter <= total_time) {
			HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN_0_GPIO_Port, LED_GREEN_0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_YELLOW_0_GPIO_Port, LED_YELLOW_0_Pin, GPIO_PIN_SET);
			num3 = light2_counter - timeRED - timeYELLOW;
		}
		else if (timeRED < light2_counter && light2_counter <= timeRED + timeYELLOW) {
			HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN_0_GPIO_Port, LED_GREEN_0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_YELLOW_0_GPIO_Port, LED_YELLOW_0_Pin, GPIO_PIN_RESET);
			num3 = light2_counter - timeRED;
		}
		else if (0 < light2_counter && light2_counter <= timeRED) {
			HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_GREEN_0_GPIO_Port, LED_GREEN_0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_YELLOW_0_GPIO_Port, LED_YELLOW_0_Pin, GPIO_PIN_SET);
			num3 = light2_counter;
		}


		num1 = num1/10;
		num1 = num1%10;
		num3 = num3/10;
		num3 = num3%10;
		updateClockBuffer(num1, num1, num3, num3);

		if (timer1_flag == 1) {
			light1_counter--;
			light2_counter--;
			setTimer1(1000);
		}



		if (isButton1Pressed() == 1) {
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_YELLOW_0_GPIO_Port, LED_YELLOW_0_Pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN_0_GPIO_Port, LED_GREEN_0_Pin, GPIO_PIN_SET);

			state = MODE_2;
		}
		break;
	case MODE_2:
		updateClockBuffer(0, 2, tempRED/10, tempRED%10);

		if (timer2_flag == 1) {
			HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
			HAL_GPIO_TogglePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin);
			setTimer2(250);
		}

		if (isButton1Pressed() == 1) {
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_YELLOW_0_GPIO_Port, LED_YELLOW_0_Pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN_0_GPIO_Port, LED_GREEN_0_Pin, GPIO_PIN_SET);

			state = MODE_3;
		}

		if (isButton2Pressed() == 1) {
			state = MODI_2;
		}
		break;
	case MODI_2:
		tempRED++;
		if (tempRED > 99) tempRED = 0;

		if (isButton3Pressed() == 1) {
			timeRED = tempRED;
			state = MODE_2;
		}
		break;
	case MODE_3:
		updateClockBuffer(0, 3, tempYELLOW / 10, tempYELLOW % 10);

		if (timer2_flag == 1) {
			HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
			HAL_GPIO_TogglePin(LED_YELLOW_0_GPIO_Port, LED_YELLOW_0_Pin);
			setTimer2(250);
		}

		if (isButton1Pressed() == 1) {
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_YELLOW_0_GPIO_Port, LED_YELLOW_0_Pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN_0_GPIO_Port, LED_GREEN_0_Pin, GPIO_PIN_SET);

			state = MODE_4;
		}

		if (isButton2Pressed() == 1) {
			state = MODI_3;
		}
		break;
	case MODI_3:
		tempYELLOW++;
		if (tempYELLOW > 99) tempYELLOW = 0;

		if (isButton3Pressed() == 1) {
			tempYELLOW = tempYELLOW;
			state = MODE_3;
		}
		break;
	case MODE_4:
		updateClockBuffer(0, 2, tempRED/10, tempRED%10);

		if (timer2_flag == 1) {
			HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
			HAL_GPIO_TogglePin(LED_GREEN_0_GPIO_Port, LED_GREEN_0_Pin);
			setTimer2(250);
		}

		if (isButton1Pressed() == 1) {
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_RED_0_GPIO_Port, LED_RED_0_Pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_YELLOW_0_GPIO_Port, LED_YELLOW_0_Pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN_0_GPIO_Port, LED_GREEN_0_Pin, GPIO_PIN_SET);

			state = RESET;
		}

		if (isButton2Pressed() == 1) {
			state = MODI_4;
		}
		break;
	case MODI_4:
		tempGREEN++;
		if (tempGREEN > 99) tempGREEN = 0;

		if (isButton3Pressed() == 1) {
			tempGREEN = tempGREEN;
			state = MODE_4;
		}
		break;
	default:
		break;
	}
}
