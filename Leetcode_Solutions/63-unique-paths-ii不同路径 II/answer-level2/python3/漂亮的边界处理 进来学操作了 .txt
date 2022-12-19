[@yuancg](/u/yuancg/)按这位大佬写的 可以学一手边界处理
我就是在62基础上单纯加了两句话
```
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m=len(obstacleGrid)
        n=len(obstacleGrid[0])
        dp = [[0]*(n+1) for i in range(m+1)]
        dp[1][0] = 1
        for i in range(1, m+1):
            for j in range(1, n+1):
                if obstacleGrid[i-1][j-1]==1:
                    dp[i][j]=0
                    continue
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
        return dp[m][n]
```
