```python
def uniquePathsWithObstacles(dp):
    """
        1. dp问题: dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
        2. dp[i][j]当有障碍物时候, 应该归零
    """
    # 处理特殊情况
    if dp[0][0] == 1 or dp[-1][-1] == 1:
        return 0
    
    m, n = len(dp), len(dp[0])
    dp[0][0] = 1
    for i in range(m):
        for j in range(n):
            # [0,0]要特殊处理
            if i == 0 and j == 0:
                continue
            # 遇到障碍物
            if dp[i][j] != 0:
                dp[i][j] = 0
                continue
            if i - 1 >= 0:
                dp[i][j] += dp[i - 1][j]
            if j - 1 >= 0:
                dp[i][j] += dp[i][j - 1]
            
    return dp[m - 1][n - 1]

print(uniquePathsWithObstacles([[0,0],[1,0]]))
print(uniquePathsWithObstacles([[0,0,0],[0,1,0],[0,0,0]]))
print(uniquePathsWithObstacles([[0,0,0,0,0],[0,0,0,0,0],[0,0,1,0,0],[0,0,0,0,0]]))
```