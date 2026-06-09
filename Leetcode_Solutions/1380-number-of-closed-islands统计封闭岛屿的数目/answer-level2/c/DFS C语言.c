DFS搜索
```
int Dfs(int **grid, int r, int c, int gridSize, int *gridColSize) {
    int ret = 0;
    
    if (r < 0 || r >= gridSize || c < 0 || c >= *gridColSize) {
        return 0;
    }
    if (grid[r][c] == 1) {
        return 1;
    }
    //printf(" %d,  %d, grid:%d\n",  r, c, grid[r][c]);
    grid[r][c] = 1;
    ret += Dfs(grid, r - 1, c, gridSize, gridColSize);
    ret += Dfs(grid, r, c - 1, gridSize, gridColSize);
    ret += Dfs(grid, r + 1, c, gridSize, gridColSize);
    ret += Dfs(grid, r, c + 1, gridSize, gridColSize);

    return (ret == 4) ? 1 : 0;
}


int closedIsland(int** grid, int gridSize, int* gridColSize){
    int ret = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
           // printf("closedIsland %d,  %d, grid:%d\n",  i, j, grid[i][j]);
            if (grid[i][j] == 0) {
                ret += Dfs(grid, i, j, gridSize, gridColSize);
            }
        }
    }
   // printf("return num %d", ret);
    return ret;
}
```
