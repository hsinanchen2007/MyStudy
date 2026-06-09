### 解题思路
经典动态规划习题，递推式`dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]`。

### 代码

```python
class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m, n = len(grid), len(grid[0])
        dp = [[0] * n for _ in range(m)]
        sum = 0
        for j in range(n):
            sum += grid[0][j]
            dp[0][j] = sum
        sum = 0
        for i in range(m):
            sum += grid[i][0]
            dp[i][0] = sum
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]
        return dp[-1][-1]
```