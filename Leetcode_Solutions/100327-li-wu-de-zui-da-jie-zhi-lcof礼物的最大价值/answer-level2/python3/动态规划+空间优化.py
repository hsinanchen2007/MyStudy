```
class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0
        dp = [0] * (len(grid[0]) + 1)
        for i in range(len(grid)):
            for j in range(1, len(dp)):
                # 等价于dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) +grid[i][j - 1](此为j-1是因为grid和dp相同目标索引值差1)
                dp[j] = max(dp[j], dp[j - 1]) + grid[i][j - 1]
        return dp[-1]
```

