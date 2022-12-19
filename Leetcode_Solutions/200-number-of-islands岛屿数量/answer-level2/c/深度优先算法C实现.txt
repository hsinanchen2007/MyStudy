### 解题思路
此处撰写解题思路

### 代码

```c
void dfs(char** grid, int gridSize, int* gridColSize, int r, int c) {
    if (r -1 >= 0 && grid[r-1][c] == '1') {
        grid[r - 1][c] = '0';
        dfs(grid, gridSize, gridColSize, r - 1, c);
    }
    if (r + 1 < gridSize && grid[r+1][c] == '1') {
        grid[r + 1][c] = '0';
        dfs(grid, gridSize, gridColSize, r + 1, c);
    }
    if (c -1 >= 0 && grid[r][c-1] == '1') {
        grid[r][c - 1] = '0';
        dfs(grid, gridSize, gridColSize, r, c - 1);
    }
    if (c + 1 < gridColSize[r] && grid[r][c + 1] == '1') {
        grid[r][c + 1] = '0';
        dfs(grid, gridSize, gridColSize, r, c + 1);
    }
}
int numIslands(char** grid, int gridSize, int* gridColSize){
    int result = 0;
    int i,j;
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == '1') {
                grid[i][j] = '0';
                dfs(grid, gridSize, gridColSize, i, j);
                result++;
            }
        }
    }
    return result;
}
```