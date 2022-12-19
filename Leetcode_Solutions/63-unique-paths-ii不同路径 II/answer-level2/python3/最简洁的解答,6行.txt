```
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        dp = [0 for _ in range(len(obstacleGrid[0])+1)]
        dp[0] = 1
        for i in range(len(obstacleGrid)):
            for j in range(len(obstacleGrid[0])):
                dp[j] = 0 if obstacleGrid[i][j] == 1 else dp[j] + dp[j-1]
            # print(dp)
        return dp[-2]
```
dp长度设为第二维长度加1,最后一个数恒为0是为了下一次更新第一个数，最后返回倒数第二个数
遇到障碍物则把障碍物的dp设成0即可，否则dp[j] = dp[j] + dp[j-1]
