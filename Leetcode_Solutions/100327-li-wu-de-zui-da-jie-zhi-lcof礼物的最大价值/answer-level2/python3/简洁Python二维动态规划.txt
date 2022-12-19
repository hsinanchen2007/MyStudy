### 代码

```python3
class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        if not grid or not grid[0]:
            return 0
        rows = len(grid)
        cols = len(grid[0])
        dp = [[0 for _ in range(cols)] for _ in range(rows)]
        dp[0][0] = grid[0][0]
        for row in range(rows):
            for col in range(cols):
                if row == 0 and col == 0:
                    continue
                if row == 0:
                    dp[row][col] = dp[row][col - 1] + grid[row][col]
                    continue
                if col == 0:
                    dp[row][col] = dp[row - 1][col] + grid[row][col]
                    continue
                dp[row][col] = max(dp[row][col - 1], dp[row - 1][col]) + grid[row][col]
        return dp[-1][-1]
```