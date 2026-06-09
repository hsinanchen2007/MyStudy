### 解题思路
先计算所有陆地的周长，再减去相邻陆地的长度
陆地数乘4- 相邻陆地数乘2

### 代码

```c
int islandPerimeter(int** grid, int gridSize, int* gridColSize)
{
    int i, j;
    int len;        // 周长
    int cnt = 0;    // 所有1的个数
    int r = 0;      // 左右相邻的1的个数
    int d = 0;      // 上下相邻的1的个数
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == 1) {
                cnt++;
            }
        }
    }
    for (i = 0; i < gridSize; i++) {
        for (j = 1; j < *gridColSize; j++) {
            if (grid[i][j] == 1 && grid[i][j] == grid[i][j - 1] && grid[i][j - 1] == 1) {
                r++;
            }
        }
    }
    for (i = 1; i < gridSize; i++) {
        for (j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == 1 && grid[i - 1][j] == grid[i][j] && grid[i - 1][j] == 1) {
                d++;
            }
        }
    }
    len = cnt * 4 - (r + d) * 2;
    return len;
}
```