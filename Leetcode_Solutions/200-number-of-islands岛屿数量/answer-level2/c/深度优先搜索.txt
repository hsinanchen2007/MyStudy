```
void dfs(char** grid, int gridSize, int* gridColSize,int row, int col){
    if (grid[row][col] == '0') {
        return;
    }

    grid[row][col] = '0';
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int x, y, k;

    for (k = 0; k < 4; k++) {
        x = row + dx[k];
        y = col + dy[k];

        if (x >= 0 && x < gridSize  && y >= 0 && y < gridColSize[0]) {
            if (grid[x][y] == '0') {
                continue;
            }
            dfs(grid, gridSize, gridColSize, x, y);
        }
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    int i, j;
    int num = 0;
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j] == '1') {
                num++;
                dfs(grid, gridSize, gridColSize, i, j);
            }
        }
    }
    return num;
}
```
