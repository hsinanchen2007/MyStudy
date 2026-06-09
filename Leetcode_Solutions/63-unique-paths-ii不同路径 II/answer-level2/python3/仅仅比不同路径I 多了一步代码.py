思路：
1）设输入数组的行和列为n,m
2）建立一个全为0的dp[n+1][m+1]
3) 另数组的dp[0][1] = 1 或者dp[1][0] = 1
4) 两层循环分别从1开始遍历dp 和 obstacleGrid
5）判断obstacleGrid[i-1][j-1] 是否为1， 如果为1，则是障碍物，否则不是
5）如果为1，则dp[i][j] = 0， 否则dp[i][j] = dp[i-1][j] + dp[i][j-1]
6）return dp[-1][-1]

这里说一下为什么要另dp[0][1] = 1： 如果obstacleGrid[0][0] = 0，那么dp[1][1] = dp[0][1] +dp[1][0] 也为0(实际上应该是1) ，如果另dp[0][1]=1的话，那么dp[1][1]=1，符合要求。
主要是控制dp[1][1]。


代码：
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid):
        n = len(obstacleGrid)
        m = len(obstacleGrid[0])
        dp = [[0 for _ in range(m+1)] for _ in range(n+1)]
        dp[0][1] = 1
        for i in range(1, n+1):
            for j in range(1, m+1):
                if obstacleGrid[i-1][j-1] == 0:
                    dp[i][j] = dp[i-1][j] + dp[i][j-1]
                else:
                    dp[i][j] = 0
        return  dp[-1][-1]