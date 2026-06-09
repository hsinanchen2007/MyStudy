## 动态规划（二维数组）
该题是典型动态规划题，使用二维数组 dp[i][j] 存储到第 i 行 第 j 列的路径数，则转移方程：
dp[i][j] = dp[i-1][j] + dp[i-1][j]

同样，在左侧和上侧多加一列/行，循环是i和j从1开始，避免了if...else...

```
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[0]*(n+1) for i in range(m+1)]
        dp[1][0] = 1
        for i in range(1, m+1):
            for j in range(1, n+1):
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
        return dp[m][n]
```
## 动态规划（一维数组）
每一个位置的dp值只来源于左一格和上一格，可以压缩为1维数组：
d[j] = d[j] + d[j-1]
重复以上计算过程m次即可
```
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [0, 1] + [0]*(n-1)
        for i in range(1, m+1):
            for j in range(1, n+1):
                dp[j] = dp[j] + dp[j-1]
        return dp[n]
```

