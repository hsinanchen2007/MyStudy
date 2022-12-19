### 分析
在leetcode62 不同路径的基础上，加上对当前位置是否是障碍物的判断：  
若是，当前位置的路径数置0，`dp[i][j] = 0`  
若否，`dp[i][j] = dp[i-1][j] + dp[i][j-1]`  

### 代码
```
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid):
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        if obstacleGrid[0][0] == 1:
            return 0
        obstacleGrid[0][0] = 1
        for j in range(1, n): # 第一行
            obstacleGrid[0][j] = 1 if (obstacleGrid[0][j-1]) and (not obstacleGrid[0][j]) else 0
        for i in range(1, m): # 第一列
            obstacleGrid[i][0] = 1 if (obstacleGrid[i-1][0]) and (not obstacleGrid[i][0]) else 0
        for i in range(1, m): # 其余部分
            for j in range(1, n):
                obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1] if not obstacleGrid[i][j] else 0
        return obstacleGrid[m-1][n-1]
```
