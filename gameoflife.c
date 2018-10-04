/* Main for Game of Life
Author: Deividas Puplauskas */
#include <stdio.h>
#include "conditions.h"
#include "expanded_draw.h"
#include "simple_draw.h"
#include "global_variables.h"

int main(){
  /*  Center coordinates of cell array */
  int mid_row, mid_col;

  /* Two identical multidimensional arrays filled with zeros */
  char *c, *c_copy;
  char cells[ROWS][COLUMNS]= {0};
  char new_cells[ROWS][COLUMNS]= {0};

  /* We want to reuse these arrays but cannot assign values to arrays,
  so we use pointers instead */
  c = &cells[0][0];
  c_copy = &new_cells[0][0];

  /* Drawing the grid */
  draw_initialize();

  /* Defining center coordinates */
  mid_row = ROWS/2;
  mid_col = COLUMNS/2;

  /* Setting our muster of live cells */
  /*
  set_cell((char *)c, mid_row, mid_col);
  set_cell((char *)c, mid_row, mid_col+2);
  set_cell((char *)c, mid_row, mid_col+4);
  set_cell((char *)c, mid_row+1, mid_col);
  set_cell((char *)c, mid_row+1, mid_col+4);
  set_cell((char *)c, mid_row+2, mid_col);
  set_cell((char *)c, mid_row+2, mid_col+4);
  set_cell((char *)c, mid_row+3, mid_col);
  set_cell((char *)c, mid_row+3, mid_col+4);
  set_cell((char *)c, mid_row+4, mid_col);
  set_cell((char *)c, mid_row+4, mid_col+2);
  set_cell((char *)c, mid_row+4, mid_col+4);
*/
set_cell((char *)c, mid_row, mid_col);
set_cell((char *)c, mid_row+1, mid_col+1);
set_cell((char *)c, mid_row+2, mid_col-1);
set_cell((char *)c, mid_row+2, mid_col);
set_cell((char *)c, mid_row+2, mid_col+1);

  /* Making both cell arrays identical */
  copy_cells((char *)c, (char *)c_copy);

  /* A bit of delay to see the setting of live cells */
  for (int i = 0; i < 114748360; i++) {
  }

  /* Looping the game of life */
  for (int i = 0; i < 50; i++) {
    /* Calculating and drawing new cells */
    calculate_cells_v2((char *)c, (char *)c_copy);

    /* Delaying a bit to see the cells */
    for (int i = 0; i < 114748360; i++) {
    }
  }
  return 0;
}
