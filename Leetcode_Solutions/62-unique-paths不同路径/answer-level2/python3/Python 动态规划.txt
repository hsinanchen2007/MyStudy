这题应该归到简单题。枚举几个格子的数值，很容易发现状态转移方程 dp[i][j]=dp[i-1][j]+dp[i][j-1]。
其他就是初始化，并且修补下特殊情况的数值。

```
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        if m==0 or n==0:                   #两种特殊情况
            return 0
        if m==1 and n==1:
            return 1
        dp = [[0 for i1 in range(m)] for j1 in range(n)]     #初始化，放入0
        for i in range(m):                                  #基础情况，第一行和第一列都是1
            dp[0][i] = 1
        for j in range(n):
            dp[j][0] = 1

        for i in range(1,n):                        #动态规划
            for j in range(1,m):
                dp[i][j]=dp[i-1][j]+dp[i][j-1]
        return dp[n-1][m-1]
```
