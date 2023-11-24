/*
 * global.c
 *
 *  Created on: Nov 24, 2023
 *      Author: lequo
 */

#include "main.h"
#include "global.h"

int T_RED = 5;
int T_AMBER = 2;
int T_GREEN = 3;

int status = INIT;
int toggle_flag = 0;

enum PEDESTRIAN_STATE curr_ped_status=PED_OFF;

void off_all_leds_road_1();
void off_all_leds_road_2();
void on_red_road_1();
void on_red_road_2();
void on_amber_road_1();
void on_amber_road_2();
void on_green_road_1();
void on_green_road_2();
void off_pedestrian();
void on_red_pedestrian();
void on_green_pedestrian();

void led_config() {

	pedestrian_led_config();
	switch (status) {
		case MODE1:
			off_all_leds_road_1();
			off_all_leds_road_2();
			off_pedestrian();
			break;
		case RED_GREEN:
			on_red_road_1();
			on_green_road_2();

			break;
		case RED_AMBER:
			on_amber_road_2();
			break;
		case GREEN_RED:
			on_green_road_1();
			on_red_road_2();
			break;
		case AMBER_RED:
			on_amber_road_1();
			break;
		case MODE2:
			on_red_road_1();
			on_red_road_2();
			toggle_flag = 0;
			break;
		case MODE3:
			on_amber_road_1();
			on_amber_road_2();
			toggle_flag = 0;
			break;
		case MODE4:
			on_green_road_1();
			on_green_road_2();
			toggle_flag = 0;
			break;
		default:
			break;
	}
}
void pedestrian_led_config(){
	switch (status) {
			case MODE1:
				off_pedestrian();
				break;
			case RED_GREEN:
				if(curr_ped_status==PED_ON){
					on_green_pedestrian();
					break;
				}
				off_pedestrian();
				break;
			case RED_AMBER:
				if(curr_ped_status==PED_ON){
					on_green_pedestrian();
					break;
				}
				off_pedestrian();
				break;
			case GREEN_RED:
				if(curr_ped_status==PED_ON){
					on_red_pedestrian();
					break;
				}
				off_pedestrian();
				break;
			case AMBER_RED:
				if(curr_ped_status==PED_ON){
					on_red_pedestrian();
					break;
				}
				off_pedestrian();
				break;
			case MODE2:
				curr_ped_status=PED_OFF;
				off_pedestrian();
				break;
			case MODE3:
				curr_ped_status=PED_OFF;
				off_pedestrian();
				break;
			case MODE4:
				curr_ped_status=PED_OFF;
				off_pedestrian();
				break;
			default:
				break;
		}
}
void off_all_leds_road_1() {
	HAL_GPIO_WritePin (D2_LED1_GPIO_Port, D2_LED1_Pin, 0);
	HAL_GPIO_WritePin (D3_LED1_GPIO_Port, D3_LED1_Pin, 0);
}

void off_all_leds_road_2() {
	HAL_GPIO_WritePin (D4_LED2_GPIO_Port, D4_LED2_Pin, 0);
	HAL_GPIO_WritePin (D5_LED2_GPIO_Port, D5_LED2_Pin, 0);
}

void on_red_road_1() {
	HAL_GPIO_WritePin (D2_LED1_GPIO_Port, D2_LED1_Pin, 1);
	HAL_GPIO_WritePin (D3_LED1_GPIO_Port, D3_LED1_Pin, 0);
}

void on_red_road_2() {
	HAL_GPIO_WritePin (D4_LED2_GPIO_Port, D4_LED2_Pin, 1);
	HAL_GPIO_WritePin (D5_LED2_GPIO_Port, D5_LED2_Pin, 0);
}

void on_amber_road_1() {
	HAL_GPIO_WritePin (D2_LED1_GPIO_Port, D2_LED1_Pin, 1);
	HAL_GPIO_WritePin (D3_LED1_GPIO_Port, D3_LED1_Pin, 1);
}

void on_amber_road_2() {
	HAL_GPIO_WritePin (D4_LED2_GPIO_Port, D4_LED2_Pin, 1);
	HAL_GPIO_WritePin (D5_LED2_GPIO_Port, D5_LED2_Pin, 1);
}

void on_green_road_1() {
	HAL_GPIO_WritePin (D2_LED1_GPIO_Port, D2_LED1_Pin, 0);
	HAL_GPIO_WritePin (D3_LED1_GPIO_Port, D3_LED1_Pin, 1);
}

void on_green_road_2() {
	HAL_GPIO_WritePin (D4_LED2_GPIO_Port, D4_LED2_Pin, 0);
	HAL_GPIO_WritePin (D5_LED2_GPIO_Port, D5_LED2_Pin, 1);
}


void toggle_red() {
	if (toggle_flag == 0) {
		on_red_road_1();
		on_red_road_2();
		toggle_flag = 1;
	} else {
		off_all_leds_road_1();
		off_all_leds_road_2();
		toggle_flag = 0;
	}
}

void toggle_amber() {
	if (toggle_flag == 0) {
		on_amber_road_1();
		on_amber_road_2();
		toggle_flag = 1;
	} else {
		off_all_leds_road_1();
		off_all_leds_road_2();
		toggle_flag = 0;
	}
}

void toggle_green() {
	if (toggle_flag == 0) {
		on_green_road_1();
		on_green_road_2();
		toggle_flag = 1;
	} else {
		off_all_leds_road_1();
		off_all_leds_road_2();
		toggle_flag = 0;
	}
}

void off_pedestrian(){
	HAL_GPIO_WritePin (D6_PedLED_GPIO_Port, D6_PedLED_Pin, 0);
	HAL_GPIO_WritePin (D7_PedLED_GPIO_Port, D7_PedLED_Pin, 0);
}
void on_red_pedestrian(){
	HAL_GPIO_WritePin (D6_PedLED_GPIO_Port, D6_PedLED_Pin, 1);
	HAL_GPIO_WritePin (D7_PedLED_GPIO_Port, D7_PedLED_Pin, 0);
}
void on_green_pedestrian(){
	HAL_GPIO_WritePin (D6_PedLED_GPIO_Port, D6_PedLED_Pin, 0);
	HAL_GPIO_WritePin (D7_PedLED_GPIO_Port, D7_PedLED_Pin, 1);
}

