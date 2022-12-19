### 解题思路
上代码

### 代码

```c
int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int ret = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] > 0) {
                ret += 6 * grid[i][j] - (grid[i][j] - 1) * 2;
            }
        }
    }
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (i < gridSize - 1) {
                ret -= 2 * (grid[i][j] < grid[i + 1][j] ? grid[i][j] : grid[i + 1][j]);
            }
            if (j < gridColSize[i] - 1) {
                ret -= 2 * (grid[i][j] < grid[i][j + 1] ? grid[i][j] : grid[i][j + 1]);
            }
        }
    }
    return ret;
}
```