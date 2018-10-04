/* Functions to calculate new cell arrays, copy cell arrays and set some arrays alive
* Author: Deividas Puplauskas */
#include "global_variables.h"
#include "expanded_draw.h"

char *calculate_cells(char *cells, char *new_cells, int rows, int cols);
void set_cell(char *cells, int row, int col);
void copy_cells(char *from, char *to);
void calculate_cells_v2(char *cells, char *dummy);

/* old version, too lazy to comment it, works basically the same as newer one */
char *calculate_cells(char *cells, char *new_cells, int rows, int cols){
  int row, col;
  for (row = 1; row < rows-1; row++) {
    for (col = 1; col < cols-1; col++) {
      char sum_neighbor, current_cell;
      sum_neighbor = *((cells+(row-1)*cols) + col-1) +
      *((cells+(row-1)*cols) + col) +
      *((cells+(row-1)*cols) + col+1) +
      *((cells+row*cols) + col-1) +
      *((cells+row*cols) + col+1) +
      *((cells+(row+1)*cols) + col-1) +
      *((cells+(row+1)*cols) + col) +
      *((cells+(row+1)*cols) + col+1);
      current_cell = *((cells+row*cols) + col);
      if((current_cell == 1) && (sum_neighbor < 2)){
        *((new_cells+row*cols) + col) = 0;
        draw_cell_v2(row, col, 0);
      }
      else if((current_cell == 1) && (sum_neighbor > 3)){
        *((new_cells+row*cols) + col) = 0;
        draw_cell_v2(row, col, 0);
      }
      else if(current_cell == 1){
        *((new_cells+row*cols) + col) = 1;
        draw_cell_v2(row, col, 1);
      }
      else if((current_cell == 0) && (sum_neighbor == 3)){
        *((new_cells+row*cols) + col) = 1;
        draw_cell_v2(row, col, 1);
      }
    }
  }
  return new_cells;
}

/* Newer version to calculate and draw cell arrays
Two identical cell arrays are used, one is being updated while second is
for calculation. When new cell array is done, it is copied to the other one */
void calculate_cells_v2(char *cells, char *dummy){
  int row, col;
  /* We go through the whole array to calculate each cell, expect the border ones*/
  for (row = 1; row < ROWS-1; row++) {
    for (col = 1; col < COLUMNS-1; col++) {
      char sum_neighbor, current_cell;
      /* 8 neighbors of the cell are added for the new cell condition */
      sum_neighbor = *((dummy+(row-1)*COLUMNS) + col-1) +
      *((dummy+(row-1)*COLUMNS) + col) +
      *((dummy+(row-1)*COLUMNS) + col+1) +
      *((dummy+row*COLUMNS) + col-1) +
      *((dummy+row*COLUMNS) + col+1) +
      *((dummy+(row+1)*COLUMNS) + col-1) +
      *((dummy+(row+1)*COLUMNS) + col) +
      *((dummy+(row+1)*COLUMNS) + col+1);

      current_cell = *((dummy+row*COLUMNS) + col);

      /* Possible conditions for the cell, it gets updated and drawn */
      /* Each cell with one or no neighbors dies, as if by solitude. */
      if((current_cell == 1) && (sum_neighbor < 2)){
        *((cells+row*COLUMNS) + col) = 0;
        draw_cell_v2(row, col, 0);
      }
      /* Each cell with four of more neighbors dies, as if by overpopulation. */
      else if((current_cell == 1) && (sum_neighbor > 3)){
        *((cells+row*COLUMNS) + col) = 0;
        draw_cell_v2(row, col, 0);
      }
      /* Otherwise (2or3 neighbors) cell survives. */
      else if(current_cell == 1){
        *((cells+row*COLUMNS) + col) = 1;
        draw_cell_v2(row, col, 1);
      }
      /* Each cell with three neighbors becomes populated. */
      else if((current_cell == 0) && (sum_neighbor == 3)){
        *((cells+row*COLUMNS) + col) = 1;
        draw_cell_v2(row, col, 1);
      }
    }
  }
  /* Making both cell arrays identical again */
  copy_cells((char *)cells, (char *)dummy);
}

/* Copying cells one by one, expect borders */
void copy_cells(char *from, char *to){
  int row, col;
  for (row = 1; row < ROWS-1; row++) {
    for (col = 1; col < COLUMNS-1; col++) {
      *((to+row*COLUMNS) + col) = *((from+row*COLUMNS) + col);
    }
  }
}

/* Sets cell to alive and draws it in graphic */
void set_cell(char *cells, int row, int col){
  *((cells+row*COLUMNS) + col) = 1;
  draw_cell_v2(row, col, 1);
}
