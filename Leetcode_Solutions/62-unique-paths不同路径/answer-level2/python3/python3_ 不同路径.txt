```python
def uniquePaths(m, n):
    """
        1. dp问题, dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
        2. 第一行, 第一列均为1
    """
    dp = [[0 for _ in range(n)] for _ in range(m)]
    for i in range(n):
        dp[0][i] = 1
    for i in range(m):
        dp[i][0] = 1
    for i in range(1, m):
        for j in range(1, n):
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
            
    return dp[m - 1][n - 1]

print(uniquePaths(7, 3))
```