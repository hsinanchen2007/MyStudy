### 解题思路
动态规划思想做这题，状态计算dp[i][j] = dp[i-1][j] + dp[i][j-1]，初始状态 dp[0][0] = 1 if obstacleGrid[0][0] != 1 else 0

### 代码

```python3
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        n = len(obstacleGrid)
        m = len(obstacleGrid[0])
        dp = [[0] * m for i in range(n)]
        dp[0][0] = 1 if obstacleGrid[0][0] != 1 else 0
        for i in range(n):
            for j in range(m):
                if obstacleGrid[i][j]:
                    continue
                if i > 0:
                    dp[i][j] += dp[i-1][j]
                if j > 0:
                    dp[i][j] += dp[i][j-1]
        return dp[n-1][m-1]
```