#ifndef __RGB_H__
#define __RGB_H__

#include "main.h"

#define CODE_1 (58)
#define CODE_0 (25)

typedef struct
{
	uint8_t R;
	uint8_t G;
	uint8_t B;
} RGB_Color_TypeDef;

/*一些常见颜色*/
extern const RGB_Color_TypeDef RED;
extern const RGB_Color_TypeDef BLUE;
extern const RGB_Color_TypeDef GREEN;
extern const RGB_Color_TypeDef BLACK;
extern const RGB_Color_TypeDef WHITE;


#define Pixel_NUM 8

void RGB_SetSingleColor(uint16_t LedId, RGB_Color_TypeDef Color);

void Reset_Load(void);

void RGB_SetColors(uint16_t Pixel_Len, RGB_Color_TypeDef Color);

void RGB_SendArray(TIM_HandleTypeDef *htimx, const uint32_t channel);

#endif
