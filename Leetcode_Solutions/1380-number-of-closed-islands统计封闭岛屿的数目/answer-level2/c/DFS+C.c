### 解题思路
从一个岛屿开始深度搜索，满足条件g_num=1，并进行累加；不满足条件g_num=0。参考其他题解完成的。

### 代码

```c
void dfs(int i, int j, int** grid, int gridSize, int gridColSize, int *g_num)
{
    if (i < 0 || i >= gridSize || j < 0 || j >= gridColSize) {
        *g_num = 0;
        return;
    }

    if (grid[i][j] != 0) return;
    grid[i][j] = -1;

    dfs(i + 1, j, grid, gridSize, gridColSize, g_num);
    dfs(i - 1, j, grid, gridSize, gridColSize, g_num);
    dfs(i, j + 1, grid, gridSize, gridColSize, g_num);
    dfs(i, j - 1, grid, gridSize, gridColSize, g_num);       
}


int closedIsland(int** grid, int gridSize, int* gridColSize){
    int g_num = 0;
    int res = 0;
    for(int i = 0; i < gridSize; i++) {
        for(int j = 0; j < gridColSize[0]; j++) {
            if(grid[i][j] == 0) {
                g_num = 1;
                dfs(i, j, grid, gridSize, gridColSize[0], &g_num);
                res += g_num;
            }
        }
    }
    return res;
}
```