#include "input.h"

#ifndef GAME_H
#define GAME_H

//game states
typedef enum {
	DEFAULT,
	MENU,
	INIT,
	GAME,
	GAMEOVER
} game_state_t;

//menu states
typedef enum {
	SINGLEPLAYER,
	MULTIPLAYER,
	OPTIONS,
	EXIT,
	DIFFICULTY_EASY,
	DIFFICULTY_MEDIUM,
	DIFFICULTY_HARD
} menu_state_t;

//difficulty levels
typedef enum {
	EASY = 1,
	MEDIUM,
	HARD
} difficulty_t;

//menu levels
typedef enum {
	MAIN,
	SETTINGS
} menu_level_t;

//general flags
typedef struct {
	bool game_refresh : 1;
	bool remove_caption : 1;
	bool summary_done : 1;
	bool change_refreshing_freq : 1;
	bool game_paused : 1;
	bool pause_triggered : 1;
	uint8_t reserved : 2;
} game_flags_t;

//singleplayer gamemode flags
typedef struct {
	bool platform_move : 1;
	bool init_shift : 1;
	bool ball_move : 1;
	bool game_init_done : 1;
	uint8_t reserved : 4;
} sp_flags_t;

//multiplayer gamemode flags - to be added in the future
typedef struct {

} mp_flags_t;

extern joystick_t joystick1;
extern joystick_t joystick2;

void Main_Game(void);
void Button1_Handler(void);
void Joystick1_Yaxis_Handler(void);
void Objects_TIM_Handler(void);
void Platforms_TIM_Handler(void);
void Refresh_TIM_Handler(void);

#endif
