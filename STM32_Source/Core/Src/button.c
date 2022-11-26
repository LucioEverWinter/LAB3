/*
 * button.c
 *
 *  Created on: Nov 15, 2022
 *      Author: BIN
 */

#include "button.h"

/*int KeyReg0_MODE = NORMAL_STATE;
int KeyReg1_MODE = NORMAL_STATE;
int KeyReg2_MODE = NORMAL_STATE;
int KeyReg3_MODE = NORMAL_STATE;

int KeyReg0_TIME = NORMAL_STATE;
int KeyReg1_TIME = NORMAL_STATE;
int KeyReg2_TIME = NORMAL_STATE;
int KeyReg3_TIME = NORMAL_STATE;

int KeyReg0_SET = NORMAL_STATE;
int KeyReg1_SET = NORMAL_STATE;
int KeyReg2_SET = NORMAL_STATE;
int KeyReg3_SET = NORMAL_STATE;*/


int KeyReg0[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg1[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg2[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg3[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

int MODE_flag = 0;
int TIME_flag = 0;
int SET_flag = 0;

int MODE_PRESSED() {
	if (MODE_flag == 1) {
		MODE_flag = 0;
		return 1;
	}
	return 0;
}

int TIME_PRESSED() {
	if (TIME_flag == 1) {
		TIME_flag = 0;
		return 1;
	}
	return 0;
}

int SET_PRESSED() {
	if (SET_flag == 1) {
		SET_flag = 0;
		return 1;
	}
	return 0;
}


void setKeyReg2(int i) {
	if (i == 0) KeyReg2[i] = HAL_GPIO_ReadPin(BUTTON_MODE_GPIO_Port, BUTTON_MODE_Pin);
	if (i == 1) KeyReg2[i] = HAL_GPIO_ReadPin(BUTTON_TIME_GPIO_Port, BUTTON_TIME_Pin);
	if (i == 2) KeyReg2[i] = HAL_GPIO_ReadPin(BUTTON_SET_GPIO_Port, BUTTON_SET_Pin);
}

void setFlag(int i) {
	if (i == 0) MODE_flag = 1;
	if (i == 1) TIME_flag = 1;
	if (i == 2) SET_flag = 1;
}


void getKeyInput() {

	for (int i = 0; i < 3; i++) {
		KeyReg0[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg2[i];
	}


	//KeyReg2[0] = HAL_GPIO_ReadPin(BUTTON_MODE_GPIO_Port, BUTTON_MODE_Pin);
	//KeyReg2[1] = HAL_GPIO_ReadPin(BUTTON_TIME_GPIO_Port, BUTTON_TIME_Pin);
	//KeyReg2[2] = HAL_GPIO_ReadPin(BUTTON_SET_GPIO_Port, BUTTON_SET_Pin);



	for (int i = 0; i < 3; i++) {
		KeyReg0[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg2[i];

		setKeyReg2(i);


		if ((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i])) {
			if (KeyReg3[i] != KeyReg2[i]) {
				KeyReg3[i] = KeyReg2[i];
				if (KeyReg2[i] == NORMAL_STATE) {
					setFlag(i);
				}
			}
		}
	}


	/*if ((KeyReg0[0] == KeyReg1[0]) && (KeyReg1[0] == KeyReg2[0])){
		if (KeyReg3[0] != KeyReg2[0]) {
			KeyReg3[0] = KeyReg2[0];
			if (KeyReg2[0] == NORMAL_STATE) {
				MODE_flag = 1;
			}
		}
	}

	if ((KeyReg0[1] == KeyReg1[1]) && (KeyReg1[1] == KeyReg2[1])){
		if (KeyReg3[1] != KeyReg2[1]) {
			KeyReg3[1] = KeyReg2[1];
			if (KeyReg2[1] == NORMAL_STATE) {
				TIME_flag = 1;
			}
		}
	}

	if ((KeyReg0[2] == KeyReg1[2]) && (KeyReg1[2] == KeyReg2[2])){
		if (KeyReg3[2] != KeyReg2[2]) {
			KeyReg3[2] = KeyReg2[2];
			if (KeyReg2[2] == NORMAL_STATE) {
				SET_flag = 1;
			}
		}
	}*/

}


/*void getKeyInputMODE() {
	KeyReg0_MODE = KeyReg1_MODE;
	KeyReg1_MODE = KeyReg2_MODE;
	KeyReg2_MODE = HAL_GPIO_ReadPin(BUTTON_MODE_GPIO_Port, BUTTON_MODE_Pin);

	if ((KeyReg0_MODE == KeyReg1_MODE) && (KeyReg1_MODE == KeyReg2_MODE)) {
		if (KeyReg3_MODE != KeyReg2_MODE) {
			KeyReg3_MODE = KeyReg2_MODE;
			if (KeyReg2_MODE == NORMAL_STATE) {
				MODE_flag = 1;
			}
		}
	}
}

void getKeyInputTIME() {
	KeyReg0_TIME = KeyReg1_TIME;
	KeyReg1_TIME = KeyReg2_TIME;
	KeyReg2_TIME = HAL_GPIO_ReadPin(BUTTON_TIME_GPIO_Port, BUTTON_TIME_Pin);

	if ((KeyReg0_TIME == KeyReg1_TIME) && (KeyReg1_TIME == KeyReg2_TIME)) {
		if (KeyReg3_TIME != KeyReg2_TIME) {
			KeyReg3_TIME = KeyReg2_TIME;
			if (KeyReg2_TIME == NORMAL_STATE) {
				TIME_flag = 1;
			}
		}
	}
}

void getKeyInputSET() {
	KeyReg0_SET = KeyReg1_SET;
	KeyReg1_SET = KeyReg2_SET;
	KeyReg2_SET = HAL_GPIO_ReadPin(BUTTON_SET_GPIO_Port, BUTTON_SET_Pin);

	if ((KeyReg0_SET == KeyReg1_SET) && (KeyReg1_SET == KeyReg2_SET)) {
		if (KeyReg3_SET != KeyReg2_SET) {
			KeyReg3_SET = KeyReg2_SET;
			if (KeyReg2_SET == NORMAL_STATE) {
				SET_flag = 1;
			}
		}
	}
}*/
