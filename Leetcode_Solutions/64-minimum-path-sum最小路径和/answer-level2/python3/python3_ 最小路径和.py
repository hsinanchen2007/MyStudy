```python
def minPathSum(dp):
    """
        1. dp问题: dp[i][j] += min(dp[i-1][j], dp[i][j-1])
    """
    m, n = len(dp), len(dp[0])
    for i in range(m):
        for j in range(n):
            if i - 1 >= 0 and j - 1 >= 0:
                dp[i][j] += min(dp[i-1][j], dp[i][j-1])
            elif i - 1 >= 0:
                dp[i][j] += dp[i-1][j]
            elif j - 1 >= 0:
                dp[i][j] += dp[i][j-1]
                
    return dp[m-1][n-1]

print(minPathSum([[1,3,1],[1,5,1],[4,2,1]]))
```