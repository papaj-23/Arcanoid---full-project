#include<stdint.h>
#include<stdbool.h>

#ifndef SINGLEPLAYER_H

#define SINGLEPLAYER_H

//there are 4 possible ball directions - all are diagonal
typedef enum {
	DEG45,
	DEG135,
	DEG225,
	DEG315
} direction_t;

//contains types of bonuses
typedef enum {
	X2_SCORE,
	WIDER_PLATFORM
} bonus_type_t;

//contains data about a specific bonus
typedef struct {
	uint16_t duration_ms;
	bool is_active;
} bonus_t;

typedef struct {
	bool gameover : 1;
	bool game_restart : 1;
	bool block_reflection : 1;
	uint8_t reserved : 5;
} game_t;

//data about current session
typedef struct {
	unsigned int score;
	uint8_t remaining_lives;
	bonus_t bonuses[2];
} gui_data_t;

typedef struct {
	int x;
	int x_previous;
	int width;
	int velocity;
	int shift_velocity;
} platform_t;

typedef struct{
	int x;
	int y;
	int x_previous;
	int y_previous;
	direction_t direction;
} ball_t;

/*
  Structure holding 5 collision test points around the ball.
  Each point is defined as [x, y] coordinates.

  The points are relative to the current ball direction:
    - p3 lies directly in the direction of the ball (diagonal hit point)
    - p1 and p2 are on the ball's right side (relative to its movement vector)
    - p4 and p5 are on the ball's left side (relative to its movement vector)
*/
typedef struct {
	uint8_t p1[2];
	uint8_t p2[2];
	uint8_t p3[2];
	uint8_t p4[2];
	uint8_t p5[2];
} collision_points_t;

typedef struct {
	int col;
	int row;
} BlockID_t;

void Sp_GameInit(void);
void Sp_PlatformMove(void);
void Sp_InitShift(void);
void Sp_BallMove(void);
void Sp_Summary(void);
bool Sp_Is_Game_Over(void);
void Sp_Set_Game_Over(bool state);
bool Sp_Is_Game_Restarted(void);
void Sp_Set_Game_Restart(bool state);
void Sp_Game_Restart(void);

#endif
