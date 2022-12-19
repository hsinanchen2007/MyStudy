### 解题思路
1、dp[i][j] 表示当前坐标上的表面积
2、dp[i][j] = grid[i][j] * 4 + 2 - grid[i-1][j] - grid[i+1][j] - grid[i][j-1] - grid[i][j+1]
3、需要注意在减去每个面时，要按照最小的面进行相减；
### 代码

```c
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int surfaceArea(int** grid, int gridSize, int* gridColSize){
    // dp[i][j] 表示当前位置的表面积
    // dp[i][j] = grid[i][j] * 4 + 2 - grid[i-1][j] - grid[i+1][j] - grid[i][j-1] - grid[i][j+1]
    // dp[gridSize][gridColSize[0]]
    int **dp = (int **)malloc(sizeof(int *) * gridSize);
    int i, j;
    int a, b, c, d;
    int sum = 0;

    if (gridSize == 0 || gridColSize[0] == 0) {
        return 0;
    }

    for (i = 0; i < gridSize; i++) {
        dp[i] = (int *)calloc(gridColSize[0], sizeof(int));
    }

    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[0]; j++) {
            a = 0; b = 0; c = 0; d = 0;
            if (grid[i][j] == 0) {
                dp[i][j] == 0;
            } else {
                if (i - 1 >= 0) {
                    a = MIN(grid[i][j], grid[i-1][j]); 
                }

                if (i + 1 < gridSize) {
                    b = MIN(grid[i][j], grid[i+1][j]);
                }

                if (j - 1 >= 0) {
                    c = MIN(grid[i][j], grid[i][j-1]);
                }

                if (j + 1 < gridColSize[0]) {
                    d = MIN(grid[i][j], grid[i][j+1]);
                }

                dp[i][j] = grid[i][j] * 4 + 2 - (a + b + c + d);
            }

            sum += dp[i][j];
        }
    }

    free(dp);
    return sum;
}
```