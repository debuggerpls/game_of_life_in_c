/* Function to draw the cell draw the cell grid
Parameters: height and width of the graphics screen, cell size */
void draw_grid(int height, int width, int cell_size);

/* Function to draw a cell
Parameters: x and y coordinates (left most) of the cell, size of the cell,
bw - 0 or 1, 0 for white cell, 1 for black cell */
void draw_cell(int x, int y, int size, char bw);

/* Function to draw the whole cell array, not used anymore */
void draw_cells(char *cells, char *old_cells, int rows, int cols, int cell_size);

/* Function to draw a cell
Parameters: row and column of the cell, bw - 0 or 1, 0 for white cell, 1 for black cell */
void draw_cell_v2(int row, int col, char bw);

/* Initialization of graphics
Clears the screen, resizes it and draws the grid */
void draw_initialize();
