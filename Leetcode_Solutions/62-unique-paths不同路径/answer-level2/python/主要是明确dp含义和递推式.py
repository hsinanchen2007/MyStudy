### 解题思路
感觉这种动态规划的题还是很简单的。
设dp[i][j]代表在行i列j的位置有多少条路径。
那么  dp[i][j] = dp[i-1][j] + dp[i][j-1],这个就是递推式。
初始化： 第一行，dp[i][0] = 1， 第一列：dp[0][j] = 1。因为只能直走或下行，所以只有一种路径。
OK，万事大吉。
### 代码

```python3
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[0] * n] * m
        for i in range(m):
            dp[i][0] = 1
        for j in range(n):
            dp[0][j] = 1
        for i in range(1,m):
            for j in range(1,n):
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
        return dp[m-1][n-1]
```