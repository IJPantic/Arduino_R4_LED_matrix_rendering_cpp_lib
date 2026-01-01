//Created on 28. December, 2025. by Ivan Jonjic (IJPantic on github)

//arduino R4 matrix renderer library

#include <Arduino_LED_Matrix.h>

extern bool *graphic_img[];
extern int graphic_width[];
extern int graphic_height[];

extern uint8_t frame[8][12];

extern int frame_clear(); //resets matrix frame

extern int draw_frame(int graphic, int x_offset, int y_offset); //draws directly to a matrix

extern int draw_frame_from_buffer(int step_x, int step_y, int draw_buffer[], int obj_quantity); //draws from buffer to a matrix

