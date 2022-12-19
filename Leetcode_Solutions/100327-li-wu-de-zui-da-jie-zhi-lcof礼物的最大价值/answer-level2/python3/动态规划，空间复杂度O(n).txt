```python
class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        if not grid or not grid[0]: return 0
        m, n = len(grid), len(grid[0])
        dp = [[0] * n for _ in range(m)]
        dp[0][0] = grid[0][0]
        for i in range(1, m):
            dp[i][0] = grid[i][0] + dp[i-1][0]
        for j in range(1, n):
            dp[0][j] = grid[0][j] + dp[0][j-1]
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = max(
                    dp[i-1][j], dp[i][j-1]
                ) + grid[i][j]
        return dp[-1][-1]

    def maxValue0(self, grid: List[List[int]]) -> int:
        if not grid or not grid[0]: return 0
        m, n = len(grid), len(grid[0])
        dp = [0] * n 
        for i in range(m):
            for j in range(n):
                if j > 0:
                    dp[j] = max(dp[j], dp[j-1]) + grid[i][j]
                else:
                    dp[j] = dp[j] + grid[i][j]
        return dp[-1]
```