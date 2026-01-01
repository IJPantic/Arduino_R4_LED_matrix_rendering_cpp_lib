//Created on 28. December, 2025. by Ivan Jonjic (IJPantic on github)
//Updated on 1. January, 2025. by Ivan Jonjic (IJPantic on github)

//arduino R4 matrix renderer library

#include <Arduino_LED_Matrix.h>
#include "matrix_renderer.h"

uint8_t frame[8][12] = {
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

int frame_clear(){ //resets matrix frame
  for(int i=0;i<8;i++){
    for(int j=0;j<12;j++){
      frame[i][j]=0;
    }
  }
}

int draw_frame(int graphic, int x_offset, int y_offset) { //draws directly to a matrix
  bool* char_img = graphic_img[graphic];
  int y = graphic_height[graphic];
  int x = graphic_width[graphic];
  for(int i=0;i<y;i++){
    for(int j=0;j<x;j++){
      if(i+y_offset<8 && j+x_offset<12 && i+y_offset>=0 && j+x_offset>=0){
        if(char_img[i*x+j])
          frame[i+y_offset][j+x_offset] = 1;
       else
          frame[i+y_offset][j+x_offset] = 0;
      }
    }
  }
}

int draw_frame_from_buffer(int step_x, int step_y, int draw_buffer[], int obj_quantity){ //draws from buffer to a matrix
  for(int i=0;i<obj_quantity;i++)
    draw_frame(draw_buffer[i*3], draw_buffer[i*3+1]+step_x, draw_buffer[i*3+2]+step_y);
}

