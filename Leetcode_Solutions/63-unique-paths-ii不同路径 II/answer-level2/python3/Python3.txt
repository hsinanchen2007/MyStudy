### 解题思路
遇到障碍, dp[i][j] = 0

### 代码

```python3
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        # dfs
        
        # 动态规划
        if not obstacleGrid:
            return 0
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        
        dp = [[0] * n for _ in range(m)]
        # 初始化第一行和第一列
        # 第一行或第一列一旦出现阻碍, 之后的位置都不可达
        for i in range(n):
            if obstacleGrid[0][i] == 1:
                break
            dp[0][i] = 1
        for j in range(m):
            if obstacleGrid[j][0] == 1:
                break
            dp[j][0] = 1
        
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i-1][j] + dp[i][j-1] if obstacleGrid[i][j] != 1 else 0
        return dp[-1][-1]
```