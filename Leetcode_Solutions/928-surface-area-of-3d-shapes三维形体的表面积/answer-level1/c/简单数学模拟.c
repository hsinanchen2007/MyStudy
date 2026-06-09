```c
#define DIR_ROW 4
#define DIR_COL 2
const int dir[DIR_ROW][DIR_COL] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};

int surfaceArea(int** grid, int gridSize, int* gridColSize){
    if (grid == NULL || gridSize == 0 || gridColSize[0] == 0) {
        return 0;
    }
    int area = 0;
    int i, j, k, x, y;
    for (i = 0; i < gridSize; ++i) {
        for (j = 0; j < gridColSize[i]; ++j) {
            if (!grid[i][j]) {
                continue;
            }
            area += grid[i][j] * 4 + 2;
            for (k = 0; k < DIR_ROW; ++k) {
                x = i + dir[k][0];
                y = j + dir[k][1];
                if (x < 0 || y < 0 || x >= gridSize || y >= gridColSize[i]) {
                    continue;
                }
                area -= (grid[x][y] < grid[i][j]) ? grid[x][y] : grid[i][j];
            }
        }
    }
    return area;
}
```