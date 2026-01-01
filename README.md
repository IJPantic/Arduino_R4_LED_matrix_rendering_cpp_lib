This document explains C++ rendering library for arduino R4 LED matrix (8x12 matrix).

Created on 1. January, 2025. by Ivan Jonjic (IJPantic on github)

Library includes 3 functions:
  - frame_clear(); -> sets all LEDs off

  - draw_frame(graphic, x_offset, y_offset); -> draws selected graphic directly to the frame array
    Graphic should be an integer that selects a bool array from integer graphic_img pointer that should be specified in your main code.
    It should also select an from integer graphic_width and graphic_height pointers that specify width and height of each graphic selected.
    X_offset and y_offset should be integer coordinates of a point from where the graphic will be drawn.

  - draw_frame_from_buffer(step_x, step_y, draw_buffer[], obj_quantity); -> draws selected buffer which contains graphics to the frame array
    Step_x and step_y are offset coordinates of all graphics inside of a buffer. draw_buffer should be a buffer which contents will be drawn to the frame array.
    Obj_quantity should just be integer which indicates the number of graphic objects inside a buffer.

Here is an example of these functions used in a code:
#include <Arduino_LED_Matrix.h>
#include "matrix_renderer.h" //matrix rendering library

ArduinoLEDMatrix matrix;

//graphics
int char_a_x = 4;
int char_a_y = 6;
bool char_a[24] = {
  0, 1, 0, 0,
  1, 0, 1, 0,
  1, 1, 1, 0,
  1, 0, 1, 0,
  1, 0, 1, 0,
  0, 0, 0, 0,
};

int char_b_x = 4;
int char_b_y = 6;
bool char_b[24] = {
  1, 1, 0, 0,
  1, 0, 1, 0,
  1, 1, 0, 0,
  1, 0, 1, 0,
  1, 1, 0, 0,
  0, 0, 0, 0,
};

//graphic pointers
bool *graphic_img[2]= {
  char_a,
  char_b,
};

int graphic_width[2]= {
  char_a_x,
  char_b_x,
};

int graphic_height[2]= {
  char_a_y,
  char_b_y,
};

void setup() {
  matrix.begin();
}

//draw buffer
const int buffer_obj_quantity = 3;
int draw_buffer[buffer_obj_quantity*3]{
  0,1,2, //char_a at x = 1, y = 2
  1,5,2, //char_b at x = 5, y = 2
  0,9,2, //char_a at x = 9, y = 2
};

void loop() {
  draw_frame_from_buffer(0, 0, draw_buffer, buffer_obj_quantity); //draw buffer
  matrix.renderBitmap(frame, 8, 12);
}
