比较菜，二维的感觉通俗易懂
```
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        n=len(grid[0])
        m=len(grid)
        dp=[[0 for i in range(n) ]for j in range(m)]
        for i in range(m):
            for j in range(n):
                if i==0 and j!=0:
                    dp[i][j]=grid[i][j]+dp[i][j-1]
                elif i!=0 and j==0:
                    dp[i][j]=grid[i][j]+dp[i-1][j]
                elif i!=0 and j!=0:
                    dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1])
                else:
                    dp[i][j]=grid[i][j]
        return dp[-1][-1]
```

