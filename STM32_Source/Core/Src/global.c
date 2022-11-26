/*
 * global.c
 *
 *  Created on: Nov 20, 2022
 *      Author: Admin
 */

#include "global.h"

void display7SEG(int num){
	switch(num){
	case 0:
		HAL_GPIO_WritePin ( A_GPIO_Port , A_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( B_GPIO_Port , B_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( C_GPIO_Port , C_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( D_GPIO_Port , D_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( E_GPIO_Port , E_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( F_GPIO_Port , F_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( G_GPIO_Port , G_Pin , GPIO_PIN_SET ) ;
		break;
	case 1:
		HAL_GPIO_WritePin ( A_GPIO_Port , A_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( B_GPIO_Port , B_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( C_GPIO_Port , C_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( D_GPIO_Port , D_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( E_GPIO_Port , E_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( F_GPIO_Port , F_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( G_GPIO_Port , G_Pin , GPIO_PIN_SET ) ;
		break;
	case 2:
		HAL_GPIO_WritePin ( A_GPIO_Port , A_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( B_GPIO_Port , B_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( C_GPIO_Port , C_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( D_GPIO_Port , D_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( E_GPIO_Port , E_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( F_GPIO_Port , F_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( G_GPIO_Port , G_Pin , GPIO_PIN_RESET ) ;
		break;
	case 3:
		HAL_GPIO_WritePin ( A_GPIO_Port , A_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( B_GPIO_Port , B_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( C_GPIO_Port , C_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( D_GPIO_Port , D_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( E_GPIO_Port , E_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( F_GPIO_Port , F_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( G_GPIO_Port , G_Pin , GPIO_PIN_RESET ) ;
		break;
	case 4:
		HAL_GPIO_WritePin ( A_GPIO_Port , A_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( B_GPIO_Port , B_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( C_GPIO_Port , C_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( D_GPIO_Port , D_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( E_GPIO_Port , E_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( F_GPIO_Port , F_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( G_GPIO_Port , G_Pin , GPIO_PIN_RESET ) ;
		break;
	case 5:
		HAL_GPIO_WritePin ( A_GPIO_Port , A_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( B_GPIO_Port , B_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( C_GPIO_Port , C_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( D_GPIO_Port , D_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( E_GPIO_Port , E_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( F_GPIO_Port , F_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( G_GPIO_Port , G_Pin , GPIO_PIN_RESET ) ;
		break;
	case 6:
		HAL_GPIO_WritePin ( A_GPIO_Port , A_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( B_GPIO_Port , B_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( C_GPIO_Port , C_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( D_GPIO_Port , D_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( E_GPIO_Port , E_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( F_GPIO_Port , F_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( G_GPIO_Port , G_Pin , GPIO_PIN_RESET ) ;
		break;
	case 7:
		HAL_GPIO_WritePin ( A_GPIO_Port , A_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( B_GPIO_Port , B_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( C_GPIO_Port , C_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( D_GPIO_Port , D_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( E_GPIO_Port , E_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( F_GPIO_Port , F_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( G_GPIO_Port , G_Pin , GPIO_PIN_SET ) ;
		break;
	case 8:
		HAL_GPIO_WritePin ( A_GPIO_Port , A_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( B_GPIO_Port , B_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( C_GPIO_Port , C_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( D_GPIO_Port , D_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( E_GPIO_Port , E_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( F_GPIO_Port , F_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( G_GPIO_Port , G_Pin , GPIO_PIN_RESET ) ;
		break;
	case 9:
		HAL_GPIO_WritePin ( A_GPIO_Port , A_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( B_GPIO_Port , B_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( C_GPIO_Port , C_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( D_GPIO_Port , D_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( E_GPIO_Port , E_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( F_GPIO_Port , F_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( G_GPIO_Port , G_Pin , GPIO_PIN_RESET ) ;
		break;
	default:
		break;
	}
}
void display7SEG0(int num){
	switch(num){
	case 0:
		HAL_GPIO_WritePin ( A0_GPIO_Port , A0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( B0_GPIO_Port , B0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( C0_GPIO_Port , C0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( D0_GPIO_Port , D0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( E0_GPIO_Port , E0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( F0_GPIO_Port , F0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( G0_GPIO_Port , G0_Pin , GPIO_PIN_SET ) ;
		break;
	case 1:
		HAL_GPIO_WritePin ( A0_GPIO_Port , A0_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( B0_GPIO_Port , B0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( C0_GPIO_Port , C0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( D0_GPIO_Port , D0_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( E0_GPIO_Port , E0_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( F0_GPIO_Port , F0_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( G0_GPIO_Port , G0_Pin , GPIO_PIN_SET ) ;
		break;
	case 2:
		HAL_GPIO_WritePin ( A0_GPIO_Port , A0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( B0_GPIO_Port , B0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( C0_GPIO_Port , C0_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( D0_GPIO_Port , D0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( E0_GPIO_Port , E0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( F0_GPIO_Port , F0_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( G0_GPIO_Port , G0_Pin , GPIO_PIN_RESET ) ;
		break;
	case 3:
		HAL_GPIO_WritePin ( A0_GPIO_Port , A0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( B0_GPIO_Port , B0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( C0_GPIO_Port , C0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( D0_GPIO_Port , D0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( E0_GPIO_Port , E0_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( F0_GPIO_Port , F0_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( G0_GPIO_Port , G0_Pin , GPIO_PIN_RESET ) ;
		break;
	case 4:
		HAL_GPIO_WritePin ( A0_GPIO_Port , A0_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( B0_GPIO_Port , B0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( C0_GPIO_Port , C0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( D0_GPIO_Port , D0_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( E0_GPIO_Port , E0_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( F0_GPIO_Port , F0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( G0_GPIO_Port , G0_Pin , GPIO_PIN_RESET ) ;
		break;
	case 5:
		HAL_GPIO_WritePin ( A0_GPIO_Port , A0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( B0_GPIO_Port , B0_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( C0_GPIO_Port , C0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( D0_GPIO_Port , D0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( E0_GPIO_Port , E0_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( F0_GPIO_Port , F0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( G0_GPIO_Port , G0_Pin , GPIO_PIN_RESET ) ;
		break;
	case 6:
		HAL_GPIO_WritePin ( A0_GPIO_Port , A0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( B0_GPIO_Port , B0_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( C0_GPIO_Port , C0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( D0_GPIO_Port , D0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( E0_GPIO_Port , E0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( F0_GPIO_Port , F0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( G0_GPIO_Port , G0_Pin , GPIO_PIN_RESET ) ;
		break;
	case 7:
		HAL_GPIO_WritePin ( A0_GPIO_Port , A0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( B0_GPIO_Port , B0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( C0_GPIO_Port , C0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( D0_GPIO_Port , D0_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( E0_GPIO_Port , E0_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( F0_GPIO_Port , F0_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( G0_GPIO_Port , G0_Pin , GPIO_PIN_SET ) ;
		break;
	case 8:
		HAL_GPIO_WritePin ( A0_GPIO_Port , A0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( B0_GPIO_Port , B0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( C0_GPIO_Port , C0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( D0_GPIO_Port , D0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( E0_GPIO_Port , E0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( F0_GPIO_Port , F0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( G0_GPIO_Port , G0_Pin , GPIO_PIN_RESET ) ;
		break;
	case 9:
		HAL_GPIO_WritePin ( A0_GPIO_Port , A0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( B0_GPIO_Port , B0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( C0_GPIO_Port , C0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( D0_GPIO_Port , D0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( E0_GPIO_Port , E0_Pin , GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( F0_GPIO_Port , F0_Pin , GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( G0_GPIO_Port , G0_Pin , GPIO_PIN_RESET ) ;
		break;
	default:
		break;
	}
}


int state = 0;

int time7SEG = 0;
int time7SEG0 = 0;

int timeRED = 5;
int timeGREEN = 3;
int timeYELLOW = 2;

int led_buffer[4] = {0, 0, 0, 0};


void updateClockBuffer(int num0, int num1, int num2, int num3) {
	led_buffer[0] = num0;
	led_buffer[1] = num1;
	led_buffer[2] = num2;
	led_buffer[3] = num3;
}

void update7SEG(int index) {
	switch (index) {
	case 1:
		display7SEG(led_buffer[0]);
		display7SEG0(led_buffer[1]);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
		break;
	case 2:
		display7SEG(led_buffer[2]);
		display7SEG0(led_buffer[3]);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
		break;
	default:
		break;
	}
}
