```
void getAreaOfIsland(int** grid, int gridSize, int gridColSize, int i, int j, int *area) {
    if (grid[i][j] == 1) {
        (*area)++;
        grid[i][j] = -1;
    }else {
        return;
    }
    if (i - 1 >= 0) {
        getAreaOfIsland(grid, gridSize, gridColSize, i-1, j, area);
    }
    if (i + 1 < gridSize) {
        getAreaOfIsland(grid, gridSize, gridColSize, i+1, j, area);
    }
    if (j - 1 >= 0) {
        getAreaOfIsland(grid, gridSize, gridColSize, i, j-1, area);
    }
    if (j + 1 < gridColSize) {
        getAreaOfIsland(grid, gridSize, gridColSize, i, j+1, area);
    }
}
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int max = 0;
    for(int i = 0; i < gridSize; i++) {
        for (int j = 0; j < (*gridColSize); j++) {
            if (grid[i][j] == 1) {
                int area = 0;
                getAreaOfIsland(grid, gridSize, (*gridColSize), i, j, &area);
                if (area > max) {
                    max = area;
                }
            }
        }
    }
    return max;
}
```
