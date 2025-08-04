#include "stm32f3xx_hal.h"
#include "pcd8544.h"
#include <string.h>

Buffer_t PCD8544_Buffer = {{0}, PCD8544_WIDTH - 1, 0, PCD8544_HEIGHT - 1, 0};
Buffer_t Bonus_Buffer = {{0}, PCD8544_WIDTH - 1, 0, PCD8544_HEIGHT - 1, 0};
uint8_t PCD8544_x;
uint8_t PCD8544_y;


const uint8_t PCD8544_Font5x7 [97][5] = {
	{ 0x00, 0x00, 0x00, 0x00, 0x00 },   // sp
	{ 0x00, 0x00, 0x2f, 0x00, 0x00 },   // !
	{ 0x00, 0x07, 0x00, 0x07, 0x00 },   // "
	{ 0x14, 0x7f, 0x14, 0x7f, 0x14 },   // #
	{ 0x24, 0x2a, 0x7f, 0x2a, 0x12 },   // $
	{ 0x32, 0x34, 0x08, 0x16, 0x26 },   // %
	{ 0x36, 0x49, 0x55, 0x22, 0x50 },   // &
	{ 0x00, 0x05, 0x03, 0x00, 0x00 },   // '
	{ 0x00, 0x1c, 0x22, 0x41, 0x00 },   // (
	{ 0x00, 0x41, 0x22, 0x1c, 0x00 },   // )
	{ 0x14, 0x08, 0x3E, 0x08, 0x14 },   // *
	{ 0x08, 0x08, 0x3E, 0x08, 0x08 },   // +
	{ 0x00, 0x00, 0x50, 0x30, 0x00 },   // ,
	{ 0x10, 0x10, 0x10, 0x10, 0x10 },   // -
	{ 0x00, 0x60, 0x60, 0x00, 0x00 },   // .
	{ 0x20, 0x10, 0x08, 0x04, 0x02 },   // /
	{ 0x3E, 0x51, 0x49, 0x45, 0x3E },   // 0
	{ 0x00, 0x42, 0x7F, 0x40, 0x00 },   // 1
	{ 0x42, 0x61, 0x51, 0x49, 0x46 },   // 2
	{ 0x21, 0x41, 0x45, 0x4B, 0x31 },   // 3
	{ 0x18, 0x14, 0x12, 0x7F, 0x10 },   // 4
	{ 0x27, 0x45, 0x45, 0x45, 0x39 },   // 5
	{ 0x3C, 0x4A, 0x49, 0x49, 0x30 },   // 6
	{ 0x01, 0x71, 0x09, 0x05, 0x03 },   // 7
	{ 0x36, 0x49, 0x49, 0x49, 0x36 },   // 8
	{ 0x06, 0x49, 0x49, 0x29, 0x1E },   // 9
	{ 0x00, 0x36, 0x36, 0x00, 0x00 },   // :
	{ 0x00, 0x56, 0x36, 0x00, 0x00 },   // ;
	{ 0x08, 0x14, 0x22, 0x41, 0x00 },   // <
	{ 0x14, 0x14, 0x14, 0x14, 0x14 },   // =
	{ 0x00, 0x41, 0x22, 0x14, 0x08 },   // >
	{ 0x02, 0x01, 0x51, 0x09, 0x06 },   // ?
	{ 0x32, 0x49, 0x59, 0x51, 0x3E },   // @
	{ 0x7E, 0x11, 0x11, 0x11, 0x7E },   // A
	{ 0x7F, 0x49, 0x49, 0x49, 0x36 },   // B
	{ 0x3E, 0x41, 0x41, 0x41, 0x22 },   // C
	{ 0x7F, 0x41, 0x41, 0x22, 0x1C },   // D
	{ 0x7F, 0x49, 0x49, 0x49, 0x41 },   // E
	{ 0x7F, 0x09, 0x09, 0x09, 0x01 },   // F
	{ 0x3E, 0x41, 0x49, 0x49, 0x7A },   // G
	{ 0x7F, 0x08, 0x08, 0x08, 0x7F },   // H
	{ 0x00, 0x41, 0x7F, 0x41, 0x00 },   // I
	{ 0x20, 0x40, 0x41, 0x3F, 0x01 },   // J
	{ 0x7F, 0x08, 0x14, 0x22, 0x41 },   // K
	{ 0x7F, 0x40, 0x40, 0x40, 0x40 },   // L
	{ 0x7F, 0x02, 0x0C, 0x02, 0x7F },   // M
	{ 0x7F, 0x04, 0x08, 0x10, 0x7F },   // N
	{ 0x3E, 0x41, 0x41, 0x41, 0x3E },   // O
	{ 0x7F, 0x09, 0x09, 0x09, 0x06 },   // P
	{ 0x3E, 0x41, 0x51, 0x21, 0x5E },   // Q
	{ 0x7F, 0x09, 0x19, 0x29, 0x46 },   // R
	{ 0x46, 0x49, 0x49, 0x49, 0x31 },   // S
	{ 0x01, 0x01, 0x7F, 0x01, 0x01 },   // T
	{ 0x3F, 0x40, 0x40, 0x40, 0x3F },   // U
	{ 0x1F, 0x20, 0x40, 0x20, 0x1F },   // V
	{ 0x3F, 0x40, 0x38, 0x40, 0x3F },   // W
	{ 0x63, 0x14, 0x08, 0x14, 0x63 },   // X
	{ 0x07, 0x08, 0x70, 0x08, 0x07 },   // Y
	{ 0x61, 0x51, 0x49, 0x45, 0x43 },   // Z
	{ 0x00, 0x7F, 0x41, 0x41, 0x00 },   // [
	{ 0x55, 0x2A, 0x55, 0x2A, 0x55 },   // 55
	{ 0x00, 0x41, 0x41, 0x7F, 0x00 },   // ]
	{ 0x04, 0x02, 0x01, 0x02, 0x04 },   // ^
	{ 0x40, 0x40, 0x40, 0x40, 0x40 },   // _
	{ 0x00, 0x01, 0x02, 0x04, 0x00 },   // '
	{ 0x20, 0x54, 0x54, 0x54, 0x78 },   // a
	{ 0x7F, 0x48, 0x44, 0x44, 0x38 },   // b
	{ 0x38, 0x44, 0x44, 0x44, 0x20 },   // c
	{ 0x38, 0x44, 0x44, 0x48, 0x7F },   // d
	{ 0x38, 0x54, 0x54, 0x54, 0x18 },   // e
	{ 0x08, 0x7E, 0x09, 0x01, 0x02 },   // f
	{ 0x0C, 0x52, 0x52, 0x52, 0x3E },   // g
	{ 0x7F, 0x08, 0x04, 0x04, 0x78 },   // h
	{ 0x00, 0x44, 0x7D, 0x40, 0x00 },   // i
	{ 0x20, 0x40, 0x44, 0x3D, 0x00 },   // j
	{ 0x7F, 0x10, 0x28, 0x44, 0x00 },   // k
	{ 0x00, 0x41, 0x7F, 0x40, 0x00 },   // l
	{ 0x7C, 0x04, 0x18, 0x04, 0x78 },   // m
	{ 0x7C, 0x08, 0x04, 0x04, 0x78 },   // n
	{ 0x38, 0x44, 0x44, 0x44, 0x38 },   // o
	{ 0x7C, 0x14, 0x14, 0x14, 0x08 },   // p
	{ 0x08, 0x14, 0x14, 0x18, 0x7C },   // q
	{ 0x7C, 0x08, 0x04, 0x04, 0x08 },   // r
	{ 0x48, 0x54, 0x54, 0x54, 0x20 },   // s
	{ 0x04, 0x3F, 0x44, 0x40, 0x20 },   // t
	{ 0x3C, 0x40, 0x40, 0x20, 0x7C },   // u
	{ 0x1C, 0x20, 0x40, 0x20, 0x1C },   // v
	{ 0x3C, 0x40, 0x30, 0x40, 0x3C },   // w
	{ 0x44, 0x28, 0x10, 0x28, 0x44 },   // x
	{ 0x0C, 0x50, 0x50, 0x50, 0x3C },   // y
	{ 0x44, 0x64, 0x54, 0x4C, 0x44 },   // z
	{ 0x00, 0x7F, 0x3E, 0x1C, 0x08 },   // > Filled		123
	//{ 0x08, 0x1C, 0x3E, 0x7F, 0x00 }, 	 // < Filled	124
	{ 0x18, 0x3C, 0x78, 0x3C, 0x18 },	// heart 		124
	{ 0x08, 0x7C, 0x7E, 0x7C, 0x08 },   // Arrow up		125
	{ 0x10, 0x3E, 0x7E, 0x3E, 0x10 },   // Arrow down	126
	{ 0x3E, 0x3E, 0x3E, 0x3E, 0x3E },   // Stop			127
	{ 0x00, 0x7F, 0x3E, 0x1C, 0x08 }    // Play			128
};

const uint8_t PCD8544_Font3x5[106][3] = {
	{ 0x00, 0x00, 0x00 },   // sp - 32
	{ 0x00, 0x17, 0x00 },   // ! - 33
	{ 0x03, 0x00, 0x03 },   // " - 34
	{ 0x1F, 0x0A, 0x1F },   // # - 35
	{ 0x0A, 0x1F, 0x05 },   // $
	{ 0x09, 0x04, 0x12 },   // %
	{ 0x0F, 0x17, 0x1C },   // &
	{ 0x00, 0x03, 0x00 },   // '
	{ 0x00, 0x0E, 0x11 },   // ( - 40
	{ 0x11, 0x0E, 0x00 },   // )
	{ 0x05, 0x02, 0x05 },   // *
	{ 0x04, 0x0E, 0x04 },   // +
	{ 0x10, 0x08, 0x00 },   // ,
	{ 0x04, 0x04, 0x04 },   // - - 45
	{ 0x00, 0x10, 0x00 },   // .
	{ 0x08, 0x04, 0x02 },   // /
	{ 0x1F, 0x11, 0x1F },   // 0
	{ 0x12, 0x1F, 0x10 },   // 1
	{ 0x1D, 0x15, 0x17 },   // 2 - 50
	{ 0x11, 0x15, 0x1F },   // 3
	{ 0x07, 0x04, 0x1F },   // 4
	{ 0x17, 0x15, 0x1D },   // 5
	{ 0x1F, 0x15, 0x1D },   // 6
	{ 0x01, 0x01, 0x1F },   // 7 - 55
	{ 0x1F, 0x15, 0x1F },   // 8
	{ 0x17, 0x15, 0x1F },   // 9 - 57
	{ 0x00, 0x0A, 0x00 },   // :
	{ 0x10, 0x0A, 0x00 },   // ;
	{ 0x04, 0x0A, 0x11 },   // < - 60
	{ 0x0A, 0x0A, 0x0A },   // =
	{ 0x11, 0x0A, 0x04 },   // >
	{ 0x01, 0x15, 0x03 },   // ?
	{ 0x0E, 0x15, 0x16 },   // @
	{ 0x1E, 0x05, 0x1E },   // A - 65
	{ 0x1F, 0x15, 0x0A },   // B
	{ 0x0E, 0x11, 0x11 },   // C
	{ 0x1F, 0x11, 0x0E },   // D
	{ 0x1F, 0x15, 0x15 },   // E
	{ 0x1F, 0x05, 0x05 },   // F - 70
	{ 0x0E, 0x15, 0x1D },   // G
	{ 0x1F, 0x04, 0x1F },   // H
	{ 0x11, 0x1F, 0x11 },   // I
	{ 0x08, 0x10, 0x0F },   // J
	{ 0x1F, 0x04, 0x1B },   // K - 75
	{ 0x1F, 0x10, 0x10 },   // L
	{ 0x1F, 0x06, 0x1F },   // M
	{ 0x1F, 0x0E, 0x1F },   // N
	{ 0x0E, 0x11, 0x0E },   // O
	{ 0x1F, 0x05, 0x02 },   // P - 80
	{ 0x0E, 0x11, 0x1E },   // Q
	{ 0x1F, 0x0D, 0x16 },   // R
	{ 0x12, 0x15, 0x09 },   // S
	{ 0x01, 0x1F, 0x01 },   // T
	{ 0x0F, 0x10, 0x0F },   // U - 85
	{ 0x07, 0x18, 0x07 },   // V
	{ 0x1F, 0x0C, 0x1F },   // W
	{ 0x1B, 0x04, 0x1B },   // X
	{ 0x03, 0x1C, 0x03 },   // Y
	{ 0x19, 0x15, 0x13 },   // Z - 90
	{ 0x1F, 0x11, 0x00 },   // [
	{ 0x02, 0x04, 0x08 },   // 55 - backspace - 92
	{ 0x00, 0x11, 0x1F },   // ]
	{ 0x02, 0x01, 0x02 },   // ^
	{ 0x10, 0x10, 0x10 },   // _ - 95
	{ 0x01, 0x02, 0x00 },   // `
	{ 0x1A, 0x16, 0x1C },   // a
	{ 0x1F, 0x12, 0x0C },   // b
	{ 0x0C, 0x12, 0x12 },   // c
	{ 0x0C, 0x12, 0x1F },   // d - 100
	{ 0x0C, 0x1A, 0x16 },   // e
	{ 0x04, 0x1E, 0x05 },   // f
	{ 0x06, 0x15, 0x0F },   // g
	{ 0x1F, 0x02, 0x1C },   // h
	{ 0x00, 0x1D, 0x00 },   // i - 105
	{ 0x10, 0x10, 0x0D },   // j
	{ 0x1F, 0x0C, 0x12 },   // k
	{ 0x11, 0x1F, 0x10 },   // l
	{ 0x1E, 0x0E, 0x1E },   // m
	{ 0x1E, 0x02, 0x1C },   // n - 110
	{ 0x0C, 0x12, 0x0C },   // o
	{ 0x1E, 0x0A, 0x04 },   // p
	{ 0x04, 0x0A, 0x1E },   // q
	{ 0x1C, 0x02, 0x02 },   // r
	{ 0x14, 0x1E, 0x0A },   // s - 115
	{ 0x02, 0x1F, 0x12 },   // t
	{ 0x0E, 0x10, 0x1E },   // u
	{ 0x0E, 0x10, 0x0E },   // v
	{ 0x1E, 0x1C, 0x1E },   // w
	{ 0x12, 0x0C, 0x12 },   // x - 120
	{ 0x02, 0x14, 0x1E },   // y
	{ 0x1A, 0x1E, 0x16 },   // z
	{ 0x04, 0x1B, 0x11 },   // {
	{ 0x00, 0x1F, 0x00 },   // |
	{ 0x11, 0x1B, 0x04 },   // }
	{ 0x04, 0x06, 0x02 },   // ~
	{ 0x1F, 0x1F, 0x1F }    // delete
};



uint8_t spi_soft(uint8_t dat)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	 GPIO_InitStruct.Pin = DI|SCK;
 	 GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  	 GPIO_InitStruct.Pull = GPIO_NOPULL;
  	 GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
 	 HAL_GPIO_Init(PCDPORT, &GPIO_InitStruct);
 	uint8_t cnt = 8;
	while (cnt--) {
		if (dat & 0x80)  HAL_GPIO_WritePin(PCDPORT,DI,GPIO_PIN_SET);
		else HAL_GPIO_WritePin(PCDPORT,DI,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(PCDPORT,SCK,GPIO_PIN_SET);
		dat <<= 1;
		HAL_GPIO_WritePin(PCDPORT,SCK,GPIO_PIN_RESET);
	}
	return dat;
}


void LcdWrite (uint8_t dc, uint8_t data)
{
	if (dc==0) HAL_GPIO_WritePin(PCDPORT,DC,GPIO_PIN_RESET);
	if (dc==1) HAL_GPIO_WritePin(PCDPORT,DC,GPIO_PIN_SET);
	HAL_GPIO_WritePin(PCDPORT,CEE,GPIO_PIN_RESET);
	spi_soft(data);
	HAL_GPIO_WritePin(PCDPORT,CEE,GPIO_PIN_SET);
}

void LcdClear(void)
{
	for (int index = 0; index < LCD_X * LCD_Y / 8; index++)
	{
		LcdWrite(LCD_D, 0x00);
	}
}
void LcdInitialise(void)
{
  	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.Pin = DC|RST|CEE;
 	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  	GPIO_InitStruct.Pull = GPIO_NOPULL;
  	GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
 	HAL_GPIO_Init(PCDPORT, &GPIO_InitStruct);      
        
        
        
	HAL_GPIO_WritePin(PCDPORT,RST,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(PCDPORT,RST,GPIO_PIN_SET);
	LcdWrite(LCD_C, 0x21 );  // LCD Extended Commands.
	LcdWrite(LCD_C, LCD_CONTRAST);  // Set LCD Vop (Contrast).
	LcdWrite(LCD_C, 0x04 );  // Set Temp coeffiCEEnt. //0x04
	LcdWrite(LCD_C, 0x14 );  // LCD bias mode 1:48. //0x13
	LcdWrite(LCD_C, 0x20 );  // LCD Basic Commands
	LcdWrite(LCD_C, 0x0C );  // LCD in normal mode.0x0D
}
void gotoXY(int x, int y)
{
  //LcdWrite(PCD8544_COMMAND, PCD8544_SETXADDR | x);  // Column.
  //LcdWrite(PCD8544_COMMAND, PCD8544_SETYADDR | y);  // Row.

  PCD8544_x = x;
  PCD8544_y = y;
}

void PCD8544_DrawPixel(uint8_t x, uint8_t y, PCD8544_Pixel_t pixel, Buffer_t *buffer) {
	if (x >= PCD8544_WIDTH || y >= PCD8544_HEIGHT) {
		return;
	}

	if (pixel != PCD8544_Pixel_Clear) {
		buffer->Content[x + (y / 8) * PCD8544_WIDTH] |= 1 << (y % 8);
	} else {
		buffer->Content[x + (y / 8) * PCD8544_WIDTH] &= ~(1 << (y % 8));
	}
	PCD8544_UpdateArea(x, y, x, y, buffer);
}

void PCD8544_ClearBuffer(Buffer_t *buffer) {
	memset(buffer->Content, 0, sizeof(buffer->Content));
    buffer->Update_xMin = 0;
    buffer->Update_xMax = PCD8544_WIDTH - 1;
    buffer->Update_yMin = 0;
    buffer->Update_yMax = PCD8544_HEIGHT - 1;
}

void PCD8544_Invert(PCD8544_Invert_t invert) {
	if (invert != PCD8544_Invert_No) {
		LcdWrite(PCD8544_COMMAND, PCD8544_DISPLAYCONTROL | PCD8544_DISPLAYINVERTED);
	} else {
		LcdWrite(PCD8544_COMMAND, PCD8544_DISPLAYCONTROL | PCD8544_DISPLAYNORMAL);
	}
}

void PCD8544_Home(void) {
	LcdWrite(PCD8544_COMMAND, PCD8544_SETXADDR | 0);
	LcdWrite(PCD8544_COMMAND, PCD8544_SETYADDR | 0);
}

void PCD8544_Refresh(void) {
	uint8_t i, j;
	//No refresh needed
	if(PCD8544_Buffer.Update_yMin > PCD8544_Buffer.Update_yMax || PCD8544_Buffer.Update_xMin > PCD8544_Buffer.Update_xMax) {
		return;
	}

	for (i = 0; i < 6; i++) {
		//Not in range yet
		if (((i + 1) * 8) < PCD8544_Buffer.Update_yMin) {
			continue;
		}
		//Over range, stop
		if ((i * 8) > PCD8544_Buffer.Update_yMax) {
			break;
		}

		LcdWrite(PCD8544_COMMAND, PCD8544_SETYADDR | i);
		LcdWrite(PCD8544_COMMAND, PCD8544_SETXADDR | PCD8544_Buffer.Update_xMin);

		for (j = PCD8544_Buffer.Update_xMin; j <= PCD8544_Buffer.Update_xMax; j++) {
			LcdWrite(PCD8544_DATA, PCD8544_Buffer.Content[(i * PCD8544_WIDTH) + j]);
		}
	}

	PCD8544_Buffer.Update_xMin = PCD8544_WIDTH - 1;
	PCD8544_Buffer.Update_xMax = 0;
	PCD8544_Buffer.Update_yMin = PCD8544_HEIGHT - 1;
	PCD8544_Buffer.Update_yMax = 0;
}

void PCD8544_UpdateArea(uint8_t xMin, uint8_t yMin, uint8_t xMax, uint8_t yMax, Buffer_t* buffer) {
	if (xMin < buffer->Update_xMin) {
		buffer->Update_xMin = xMin;
	}
	if (xMax > buffer->Update_xMax) {
		buffer->Update_xMax = xMax;
	}
	if (yMin < buffer->Update_yMin) {
		buffer->Update_yMin = yMin;
	}
	if (yMax > buffer->Update_yMax) {
		buffer->Update_yMax = yMax;
	}
}


void PCD8544_Putc(char c, PCD8544_Pixel_t color, PCD8544_FontSize_t size) {
	uint8_t c_height, c_width, i, b, j;
	if (size == PCD8544_FontSize_3x5) {
		c_width = PCD8544_CHAR3x5_WIDTH;
		c_height = PCD8544_CHAR3x5_HEIGHT;
	} else {
		c_width = PCD8544_CHAR5x7_WIDTH;
		c_height = PCD8544_CHAR5x7_HEIGHT;
	}

	if(PCD8544_y + c_height > PCD8544_HEIGHT) {
		return;
	}

	if (PCD8544_x + c_width > PCD8544_WIDTH) {
		//If at the end of a line of display, go to new line and set x to 0 position
		PCD8544_y += c_height;
		PCD8544_x = 0;
	}

	for (i = 0; i < c_width - 1; i++) {
		if (size == PCD8544_FontSize_3x5) {
			b = PCD8544_Font3x5[c - 32][i];
		} else {
			b = PCD8544_Font5x7[c - 32][i];
		}

		for (j = 0; j < c_height; j++) {
			if (color == PCD8544_Pixel_Set) {
				PCD8544_DrawPixel(PCD8544_x, (PCD8544_y + j), ((b >> j) & 1) ? PCD8544_Pixel_Set : PCD8544_Pixel_Clear, &PCD8544_Buffer);
			} else {
				PCD8544_DrawPixel(PCD8544_x, (PCD8544_y + j), ((b >> j) & 1) ? PCD8544_Pixel_Clear : PCD8544_Pixel_Set, &PCD8544_Buffer);
			}
		}
		PCD8544_x++;
	}
	PCD8544_x++;
}

void PCD8544_Puts(char *c, PCD8544_Pixel_t color, PCD8544_FontSize_t size) {
	while (*c) {
		PCD8544_Putc(*c++, color, size);
	}
}

void PCD8544_DrawLine(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, PCD8544_Pixel_t color, Buffer_t *buffer) {
	uint16_t dx, dy;
	uint16_t temp;

	if (x0 > x1) {
		temp = x1;
		x1 = x0;
		x0 = temp;
	}
	if (y0 > y1) {
		temp = y1;
		y1 = y0;
		y0 = temp;
	}

	dx = x1 - x0;
	dy = y1 - y0;

	if (dx == 0) {
		do {
			PCD8544_DrawPixel(x0, y0, color, buffer);
			y0++;
		} while (y1 >= y0);
		return;
	}
	if (dy == 0) {
		do {
			PCD8544_DrawPixel(x0, y0, color, buffer);
			x0++;
		} while (x1 >= x0);
		return;
	}

	/* Based on Bresenham's line algorithm  */
	if (dx > dy) {
		temp = 2 * dy - dx;
		while (x0 <= x1) {
			PCD8544_DrawPixel(x0, y0, color, buffer);
			x0++;
			if (temp > 0) {
				y0++;
				temp += 2 * dy - 2 * dx;
			} else {
				temp += 2 * dy;
			}
		}

	} else {
		temp = 2 * dx - dy;
		while (y0 <= y1) {
			PCD8544_DrawPixel(x0, y0, color, buffer);
			y0++;
			if (temp > 0) {
				x0++;
				temp += 2 * dy - 2 * dx;
			} else {
				temp += 2 * dy;
			}
		}

	}
}

void PCD8544_DrawRectangle(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, PCD8544_Pixel_t color, Buffer_t *buffer) {
	PCD8544_DrawLine(x0, y0, x1, y0, color, buffer); 	//Top
	PCD8544_DrawLine(x0, y0, x0, y1, color, buffer);	//Left
	PCD8544_DrawLine(x1, y0, x1, y1, color, buffer);	//Right
	PCD8544_DrawLine(x0, y1, x1, y1, color, buffer);	//Bottom
}

void PCD8544_DrawFilledRectangle(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, PCD8544_Pixel_t color, Buffer_t *buffer) {
	for (; y0 < y1; y0++) {
		PCD8544_DrawLine(x0, y0, x1, y0, color, buffer);
	}
}
        
void PCD8544_DrawCircle(int8_t x0, int8_t y0, int8_t r, PCD8544_Pixel_t color, Buffer_t *buffer) {
	int16_t f = 1 - r;
	int16_t ddF_x = 1;
	int16_t ddF_y = -2 * r;
	int16_t x = 0;
	int16_t y = r;

    PCD8544_DrawPixel(x0, y0 + r, color, buffer);
    PCD8544_DrawPixel(x0, y0 - r, color, buffer);
    PCD8544_DrawPixel(x0 + r, y0, color, buffer);
    PCD8544_DrawPixel(x0 - r, y0, color, buffer);

    while (x < y) {
        if (f >= 0) {
            y--;
            ddF_y += 2;
            f += ddF_y;
        }
        x++;
        ddF_x += 2;
        f += ddF_x;

        PCD8544_DrawPixel(x0 + x, y0 + y, color, buffer);
        PCD8544_DrawPixel(x0 - x, y0 + y, color, buffer);
        PCD8544_DrawPixel(x0 + x, y0 - y, color, buffer);
        PCD8544_DrawPixel(x0 - x, y0 - y, color, buffer);

        PCD8544_DrawPixel(x0 + y, y0 + x, color, buffer);
        PCD8544_DrawPixel(x0 - y, y0 + x, color, buffer);
        PCD8544_DrawPixel(x0 + y, y0 - x, color, buffer);
        PCD8544_DrawPixel(x0 - y, y0 - x, color, buffer);
    }
}

void PCD8544_DrawFilledCircle(int8_t x0, int8_t y0, int8_t r, PCD8544_Pixel_t color, Buffer_t *buffer) {
	int16_t f = 1 - r;
	int16_t ddF_x = 1;
	int16_t ddF_y = -2 * r;
	int16_t x = 0;
	int16_t y = r;

    PCD8544_DrawPixel(x0, y0 + r, color, buffer);
    PCD8544_DrawPixel(x0, y0 - r, color, buffer);
    PCD8544_DrawPixel(x0 + r, y0, color, buffer);
    PCD8544_DrawPixel(x0 - r, y0, color, buffer);
    PCD8544_DrawLine(x0 - r, y0, x0 + r, y0, color, buffer);

    while (x < y) {
        if (f >= 0) {
            y--;
            ddF_y += 2;
            f += ddF_y;
        }
        x++;
        ddF_x += 2;
        f += ddF_x;

        PCD8544_DrawLine(x0 - x, y0 + y, x0 + x, y0 + y, color, buffer);
        PCD8544_DrawLine(x0 + x, y0 - y, x0 - x, y0 - y, color, buffer);

        PCD8544_DrawLine(x0 + y, y0 + x, x0 - y, y0 + x, color, buffer);
        PCD8544_DrawLine(x0 + y, y0 - x, x0 - y, y0 - x, color, buffer);
    }
}

void PCD8544_DrawX(uint8_t x0, uint8_t y0, uint8_t shoulder_lenght /*1 is 3x3 X signature*/, PCD8544_Pixel_t color, Buffer_t *buffer) {
	if(shoulder_lenght < 1) {
		return;
	}

	PCD8544_DrawPixel(x0, y0, color, buffer);
	for(int i = 1; i <= shoulder_lenght; i++) {
		PCD8544_DrawPixel(x0 + i, y0 + i, color, buffer);
		PCD8544_DrawPixel(x0 + i, y0 - i, color, buffer);
		PCD8544_DrawPixel(x0 - i, y0 + i, color, buffer);
		PCD8544_DrawPixel(x0 - i, y0 - i, color, buffer);
	}
}

void PCD8544_DrawCross(uint8_t x0, uint8_t y0, uint8_t shoulder_lenght /*1 is 3x3 + signature*/, PCD8544_Pixel_t color, Buffer_t *buffer) {
	if(shoulder_lenght < 1) {
		return;
	}

	PCD8544_DrawPixel(x0, y0, color, buffer);
	for(int i = 1; i <= shoulder_lenght; i++) {
		PCD8544_DrawPixel(x0 + i, y0, color, buffer);
		PCD8544_DrawPixel(x0 - i, y0, color, buffer);
		PCD8544_DrawPixel(x0, y0 + i, color, buffer);
		PCD8544_DrawPixel(x0, y0 - i, color, buffer);
	}
}


