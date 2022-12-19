生成一个m*n的dp矩阵，记录走到该行该列时有多少种路径，走到m行n列时就有dp[m-1][n-1]种路径。
```
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp_ = [[0] *n for _ in range(m)]
        for i in range(0, m):
            dp_[i][0] = 1
        for j in range(1, n):
            dp_[0][j] = 1
        for i in range(1, m):
            for j in range(1, n):
                dp_[i][j] = dp_[i-1][j] + dp_[i][j-1]
        return dp_[m-1][n-1]
```
