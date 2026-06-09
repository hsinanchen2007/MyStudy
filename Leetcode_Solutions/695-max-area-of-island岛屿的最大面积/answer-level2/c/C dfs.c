### 解题思路
上代码

### 代码

```c
int dfs(int **grid, int gridSize, int* gridColSize, int i, int j) {
    if (i < 0 || j < 0 || i >= gridSize || j >= gridColSize[0] || grid[i][j] != 1) {
        return 0;
    }
    grid[i][j] = 0;
    int di[4] = {0, 0, 1, -1};
    int dj[4] = {1, -1, 0, 0};
    int ret = 1;
    for (int index = 0; index < 4; index++) {
        int nextI = i + di[index];
        int nextJ = j + dj[index];
        ret += dfs(grid, gridSize, gridColSize, nextI, nextJ);
    }
    return ret;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int ret = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            int cur = dfs(grid, gridSize, gridColSize, i, j);
            ret = ret > cur ? ret : cur;
        }
    }
    return ret;
}
```