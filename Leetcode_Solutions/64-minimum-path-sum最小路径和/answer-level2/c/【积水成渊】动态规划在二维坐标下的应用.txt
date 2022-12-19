### 解题思路
1 动态规划思路解决该问题；
2 考虑边界条件，应用于不同的状态转移方程；
3 关于为什么没有新申请空间：
    1）本来是激活申请dp[gridSize - 1][*gridColSize - 1]大小的空间；
    2）但是发现每一步求解，已经求出了最优解，不会再发生更新操作，因此可以基于原数组进行更新；
    3）而对于某些场景，如硬币拼钱，则每增加一种类型的硬币，其dp大小会发生变化，因此必须新起数组；
    4）流程是否循环；
### 代码

```c
#define min(a, b) ((a) > (b) ? (b) : (a))
int minPathSum(int** grid, int gridSize, int* gridColSize){
    int i, j;

    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < *gridColSize; j++) {
            if (i == 0 && j == 0) {
                continue;
            } else if (i == 0) {
                grid[i][j] = grid[i][j - 1] + grid[i][j];
            } else if (j == 0) {
                grid[i][j] = grid[i - 1][j] + grid[i][j];
            } else {
                grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
            }
        }
    }
    return grid[gridSize - 1][*gridColSize - 1];
}
```