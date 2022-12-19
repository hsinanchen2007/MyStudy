### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        dp = [[0] * len(grid[0]) for i in range(len(grid))]
        dp[0][0] = grid[0][0]
        for i in range(1, len(grid[0])):
            dp[0][i] = dp[0][i-1] + grid[0][i]
        for j in range(1, len(grid)):
            dp[j][0] = dp[j-1][0] + grid[j][0]
        for i in range(1, len(grid)):
            for j in range(1, len(grid[0])):
                dp[i][j] = grid[i][j] + max(dp[i-1][j], dp[i][j-1])
        return dp[-1][-1]
```