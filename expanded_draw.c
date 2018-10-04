/* Few functions to make drawing easier
* Author: Deividas Puplauskas
*/
#include <stdio.h>
#include "simple_draw.h"
#include "global_variables.h"

void draw_grid(int height, int width, int cell_size);
void draw_cells(char *cells, char *old_cells, int rows, int cols, int cell_size);
void draw_cell(int x, int y, int size, char bw);
void draw_cell_v2(int row, int col, char bw);
void draw_initialize();

/* Function to draw the cell draw the cell grid
Parameters: height and width of the graphics screen, cell size */
void draw_grid(int height, int width, int cell_size){
  /* Drawing horizontal lines */
  for (int i = 0; i <= height*(cell_size+1); i+=(cell_size+1)) {
    DrawLine(0, i, width*(cell_size+1), i);
  }

  /* Drawing vertical lines */
  for (int j = 0; j <= width*(cell_size+1); j+=(cell_size+1)) {
    DrawLine(j, 0, j, height*(cell_size+1));
  }
}

/* Function to draw the whole cell array, not used anymore */
void draw_cells(char *cells, char *old_cells, int rows, int cols, int cell_size){
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      char current_cell = *((cells+row*cols) + col);
      char old_cell = *((old_cells+row*cols) + col);
      if(current_cell != old_cell){
        draw_cell((col*(cell_size+1))+1 ,(row*(cell_size+1))+1 ,cell_size, current_cell);
      }
    }
  }
}

/* Function to draw a cell
Parameters: x and y coordinates (left most) of the cell, size of the cell,
bw - 0 or 1, 0 for white cell, 1 for black cell */
void draw_cell(int x, int y, int size, char bw){
  /* Drawing cell line by line(horizontally) */
  for (int i = 0; i < size; i++) {
      if(bw == 0){
        SetPen(255, 255, 255, 1);
        DrawLine(x, y+i, x+size-1, y+i);
      }
      else{
        SetPen(100, 100, 100, 1);
        DrawLine(x, y+i, x+size-1, y+i);
      }
  }
}

/* Function to draw a cell
Parameters: row and column of the cell, bw - 0 or 1, 0 for white cell, 1 for black cell */
void draw_cell_v2(int row, int col, char bw){
  /* Using the other draw cell function without the need to know coordinates */
  draw_cell((col*(CELL_SIZE+1))+1 ,(row*(CELL_SIZE+1))+1 ,CELL_SIZE, bw);
}

/* Initialization of graphics
Clears the screen, resizes it and draws the grid */
void draw_initialize(){
  ClearGraphic();
  ResizeGraphic(0,0,(CELL_SIZE+1)*COLUMNS+1,(CELL_SIZE+1)*ROWS+1);
  draw_grid((int)ROWS, (int)COLUMNS, (int)CELL_SIZE);
}
