`执行用时 :
48 ms
, 在所有 Python3 提交中击败了
93.35%
的用户
内存消耗 :
13 MB
, 在所有 Python3 提交中击败了
90.04%
的用户`
```
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m = len(obstacleGrid)  # m 行
        n = len(obstacleGrid[0])  # n 列
        dp = [[0] * n for _ in range(m)]
        dp[0][0] = 1 if obstacleGrid[0][0] != 1 else 0
        if dp[0][0] == 0: return 0
        for i in range(1,n):
            if obstacleGrid[0][i] == 1:
                dp[0][i] = 0
                break
            else:
                dp[0][i] = 1
        for j in range(1,m):
            if obstacleGrid[j][0] == 1:
                dp[j][0] = 0
                break
            else:
                dp[j][0] = 1
        for i in range(1,m):
            for j in range(1,n):
                if obstacleGrid[i][j] == 1:
                    dp[i][j] = 0
                else:
                    dp[i][j] = dp[i-1][j] + dp[i][j-1]
        return dp[-1][-1]
```
