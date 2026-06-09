### 解题思路
此处撰写解题思路

### 代码

```python3
'''
DP算法依然很直观：
1. state definition:
        dp[i][j] = 等于从start到 (i, j) 点上的最短距离

2. state transfer function:
        dp[i][j] = min( dp[i-1][j], dp[i][j-1] ) + grid[i][j]


3. boundary restriction:
        1. 最左边的一行，最上边的一行的初始化
        2. 当size只有一行 or 一列 or ( 一行 and 一列 ）

4. coding realization:
        填2D表即可
'''


class Solution:
    def minPathSum(self, grid) -> int:
        x = len(grid)
        y = len(grid[0][:])

        if x < 2 and y < 2:
            return grid[0][0]

        '''
        竖着的轴是 x， 横着是y，
        第一维度是x，第二维度是y  a[x][y]
        外循环是x，内循环是y
        '''

        dp = [[1000000 for _ in range(y)] for _ in range(x)]

        dp[0][0] = grid[0][0]

        for i in range(1, y):
            dp[0][i] = dp[0][i - 1] + grid[0][i]

        for i in range(1, x):
            dp[i][0] = dp[i - 1][0] + grid[i][0]

        for j in range(1, y):
            for i in range(1, x):
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]

        return dp[x - 1][y - 1]
```