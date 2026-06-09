### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        if not grid:return 0
        row,col = len(grid),len(grid[0])
        dp = [[0]*(col+1) for _ in range(row+1)]
        for i in range(1,row+1):
            for j in range(1,col+1):
                dp[i][j] = max(dp[i-1][j],dp[i][j-1])+grid[i-1][j-1]
        return dp[row][col]
```