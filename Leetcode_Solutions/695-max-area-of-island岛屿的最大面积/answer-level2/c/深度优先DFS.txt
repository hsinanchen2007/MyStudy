### 解题思路
dfs c 

### 代码

```c
void dfs(int i, int j, int** grid, int gridSize, int gridColSize, int *value)
{
    if(i < 0 || i >= gridSize) {
        return;
    }
    if(j < 0 || j >= gridColSize) {
        return;
    }
    if(grid[i][j] == 0) {
        return;
    }
    *value = *value + 1;
    grid[i][j] = 0;
    dfs(i+1, j, grid, gridSize, gridColSize, value);
    dfs(i-1, j, grid, gridSize, gridColSize, value);
    dfs(i, j+1, grid, gridSize, gridColSize, value);
    dfs(i, j-1, grid, gridSize, gridColSize, value);
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int value = 0;
    int maxValue = 0;
    int index = 0;
    int* p = (int*)malloc(gridSize*(*gridColSize) * sizeof(int));
    memset(p,0,gridSize*(*gridColSize) * sizeof(int));
    for(int i = 0; i < gridSize; i++) {
        for(int j = 0; j < gridColSize[0]; j++) {
            if(grid[i][j] == 0) {
                continue;
            }
            value = 0;
            dfs(i, j, grid, gridSize, gridColSize[0], &value);
            p[index] = value;
            index++;
        }
    }
    for(int i = 0; i < index; i++) {
        if(p[i] > maxValue) {
            maxValue = p[i];
        }
    }
    free(p);
    return maxValue;
}
```