### 解题思路
这题自己写的挺复杂的不知道其他人咋写的，就是注意第一行第一列碰到1后面的全部为0否则唯一

### 代码

```python3
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:

        Nrow = len(obstacleGrid)
        Ncol = len(obstacleGrid[0])
        colbreak = -1
        dp = [[0]*Ncol for _ in range(Nrow)]
        for n in range(Nrow):
            if obstacleGrid[n][0]==1:
                dp[n:][0] = 0
                break
            else:
                dp[n][0] = 1
        for m in range(Ncol):
            if obstacleGrid[0][m]==1:
                colbreak = m
                break
            else:
                dp[0][m] = 1
        if colbreak >= 0:
            for m in range(colbreak, Ncol):
                dp[0][m] = 0

        for i in range(1, Nrow):
            for j in range(1,Ncol):
                if obstacleGrid[i][j]==1:
                    dp[i][j] = 0
                else:
                    dp[i][j] = dp[i][j-1]+dp[i-1][j]
        # print(dp)
        return dp[Nrow-1][Ncol-1]
```