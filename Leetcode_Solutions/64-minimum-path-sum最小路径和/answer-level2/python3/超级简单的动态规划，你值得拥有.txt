### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0
        if len(grid) == 1 and len(grid[0])==1:
            return grid[0][0]
        m = len(grid)
        n = len(grid[0])
        dp = [[0]*n for i in range(m)]

        dp[0][0] = grid[0][0]
        for i in range(1,m):
            dp[i][0] = grid[i][0]+dp[i-1][0]
        
        for j in range(1,n):
            dp[0][j] = grid[0][j]+dp[0][j-1]

        for i in range(1,m):
            for j in range(1,n):
                dp[i][j] = min(dp[i-1][j],dp[i][j-1])+grid[i][j]
        
        return dp[m-1][n-1]
```