思路就是基本的dp，存储空间压缩到一维，但是边界条件的判断不需要官方题解那么复杂

```
def minPathSum(self, grid: [[int]]) -> int:
    dp = [0]*len(grid[0])
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if i == 0: 
                dp[j] = grid[i][j] + dp[j - 1] if j > 0 else 0
            elif j == 0:
                dp[j] += grid[i][j]
            else: 
                dp[j] = min(dp[j], dp[j - 1]) + grid[i][j]
    return dp[-1]
```
