### 解题思路
ij
容易得到，一个正方体有6个面，两个相邻的正方体有 6 + 6 - 2 =10 个面，相邻的两个面消去了，很容易就可以得到公式：`total = 6*n - 2(n-1) = 4n+2`,n为相邻的正方体个数。

按照这个公式，对于第i行，j列的正方体，就可以计算表面积为
第 [i, j] 行的增加的表面积为：   cur = 4*grid[i][j] +2
与 [i-1, j] 行相邻的消去表面积： del[i-1][j] = 2 * min(grid[i-1][j], grid[i][j])
与 [i, j-1] 行相邻的消去表面积： del[i][j-1] = 2 * min(grid[i-1][j], grid[i][j])

因此，计算到第[i, j] 行的总表面积为： cur - del[i-1][j] - del[i][j-1]

特殊条件如 当前 i，j 的val 值为 0，直接忽略。
所有第0行和第0列的消去表面积为0。

### 代码

```c
int min(int x, int y) {
    return x>y?y:x;
}

int surfaceArea(int** grid, int gridSize, int* gridColSize){

    int result = 0;
    int below = 0;
    int left = 0;

    for (int i=0; i<gridSize; i++) {
        for (int j=0; j<*gridColSize; j++) {

            if (i > 0) {
                below = grid[i-1][j];
            } else {
                below = 0;
            }

            if (j > 0) {
                left = grid[i][j-1];
            } else {
                left = 0;
            }
            if (grid[i][j] == 0) continue;
            result += grid[i][j] * 4 + 2 - 2*min(left, grid[i][j]) - 2*min(below, grid[i][j]);

        }
    }
    return result;
}
```