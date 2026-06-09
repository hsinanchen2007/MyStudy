```python
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        row, col = len(obstacleGrid), len(obstacleGrid[0])
        dp = [0] * col
        for i in range(row):
            for j in range(col):
                if i == 0 and j == 0:
                    dp[j] = 1 - obstacleGrid[i][j]
                    continue
                if i == 0 and obstacleGrid[i][j] == 0:
                    dp[j] = dp[j - 1]
                elif j == 0 and obstacleGrid[i][j] == 0:
                    dp[j] = dp[j]
                else:
                    if obstacleGrid[i][j] == 0:
                        dp[j] = dp[j] + dp[j - 1]
                    else:
                        dp[j] = 0
        return dp[-1]
```
