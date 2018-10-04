/* old version for cell calculation */
char *calculate_cells(char *cells, char *new_cells, int height, int width);

/* Function to set and draw a cell
Parameters: *cells - cell array, row and column of the cell */
void set_cell(char *cells, int row, int col);

/* Function to copy cell arrays */
void copy_cells(char *from, char *to);

/* Function for cell calculation in cell arrays, both arrays need to be identical
Parameters: 2 identical cell arrays */
void calculate_cells_v2(char *cells, char *dummy);
