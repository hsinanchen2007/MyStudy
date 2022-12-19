比上一题多一个判断，还是比较好写
```
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if obstacleGrid[0][0] == 1:
            return 0
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        dp = [[0 for _ in range(n)] for _ in range(m)]
        dp[0] = [1] * n
        for i in range(m):
            dp[i][0] = 1
        for i in range(1,n):
            if obstacleGrid[0][i] == 1:
                for j in range(i,n):
                    dp[0][j] = 0
                break
        for i in range(1,m):
            if obstacleGrid[i][0] == 1:
                for j in range(i,m):
                    dp[j][0] = 0
                break
        for i in range(1,m):
            for j in range(1,n):
                if obstacleGrid[i][j] == 1:
                    dp[i][j] = 0
                else:
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
        return dp[-1][-1]

        #评论区一位老哥的解法，思路是真的强(链接：https: // leetcode - cn.com / problems / unique - paths - ii / solution / python3liu - xing - jian - ji - dai - ma - shi - jian - kong - jian - /
)
        #仅在此记录一下
        # m, n = len(obstacleGrid[0]), len(obstacleGrid)
        # dp = [1] + [0]*m
        # for i in range(0, n):
        #     for j in range(0, m):
        #         dp[j] = 0 if obstacleGrid[i][j] else dp[j]+dp[j-1]
        # return dp[-2]


```
