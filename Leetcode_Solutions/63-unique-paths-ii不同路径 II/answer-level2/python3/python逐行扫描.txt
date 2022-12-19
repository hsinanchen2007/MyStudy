```python
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:           
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        # 用第一行初始化dp
        dp = [0] * (n + 1)
        dp[1] = 0 if obstacleGrid[0][0] else 1
        for j in range(1, n):
            dp[j+1] = 0 if obstacleGrid[0][j] else 0 +  dp[j]
        # 从第二行逐行扫描
        for i in range(1, m):
            for j, flag in enumerate(obstacleGrid[i], 1):
                # dp[j]代表从上面到达该点的路径数目，dp[j-1代表从左边到达该点的路径数目
                dp[j] = 0 if flag else dp[j] + dp[j - 1] 
            print(dp)
        return dp[-1]
```
