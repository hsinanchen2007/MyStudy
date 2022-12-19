### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        # 状态:每一步
        # dp[i][j]:当前状态的最大价值
        # 状态转移方程:dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + grid[i][j]
        m = len(grid)
        n = len(grid[0])
        dp = [[0 for j in range(n)] for i in range(m)]
        dp[0][0] = grid[0][0]
        for j in range(1,n):
            dp[0][j] = dp[0][j-1] + grid[0][j]
        for i in range(1,m):
            dp[i][0] = dp[i-1][0] + grid[i][0]

        for i in range(1,m):
            for j in range(1,n):
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + grid[i][j]
        return dp[m-1][n-1] 
```