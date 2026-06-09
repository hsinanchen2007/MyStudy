```
#define NULL_PTR (0)
#define TRUE (1)
#define FALSE (0)

int g_dir[4][2] = {
    {0,1},
    {0,-1},
    {1,0},
    {-1,0}
};

int g_row;
int g_col;

int IsValidCrood(int row, int col)
{
    if ((row < 0) || (row > g_row)) {
        return FALSE;
    }
    if ((col < 0) || (col > g_col)) {
        return FALSE;
    }
    return TRUE;    
}

int GetEdge(int** grid, int row, int col)
{
    int i;
    int nextRow;
    int nextCol;
    int edge = 0;
    for (i = 0; i < 4; i++) {
        nextRow = row + g_dir[i][0];
        nextCol = col + g_dir[i][1];
        if ((IsValidCrood(nextRow, nextCol) == TRUE) && (grid[nextRow][nextCol] == 0)) {
            edge++;
        }
    }
    if (row == 0) {
        edge++;
    }
    if (row == g_row) {
        edge++;
    }
    if (col == 0) {
        edge++;
    }
    if (col == g_col) {
        edge++;
    }
    return edge;
}

int islandPerimeter(int** grid, int gridSize, int* gridColSize)
{
    int i;
    int j;
    int perimter = 0;
    if ((grid == NULL_PTR) || (gridColSize == NULL_PTR)) {
        return perimter;
    }
    g_row = gridSize - 1;
    g_col = gridColSize[0] - 1;

    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j] == 1) {
                perimter += GetEdge(grid, i, j);
            }
        }
    }
    return perimter;
}
```
