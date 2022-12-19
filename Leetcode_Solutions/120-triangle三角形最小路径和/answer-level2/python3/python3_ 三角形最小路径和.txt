```python
def minimumTotal(triangle):
    """
        1. dp问题: dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1])
    """
    mini, M = triangle[-1], len(triangle)
    for i in range(M - 2, -1, -1):
        for j in range(len(triangle[i])):
            mini[j] = triangle[i][j] + min(mini[j], mini[j+1])
    
    return mini[0]

print(minimumTotal([[2],[3,4],[6,5,7],[4,1,8,3]]))
```