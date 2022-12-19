过于简单了，基本不用过脑子的那种。。练练语法基本功吧

```
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        if not grid:
            return None
        for m in range(1,len(grid)):
            grid[m][0]+=grid[m-1][0]
        
        for n in range(1,len(grid[0])):
            grid[0][n]+=grid[0][n-1]
        
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if i and j:
                    grid[i][j]+=min(grid[i-1][j],grid[i][j-1])
        return grid[-1][-1]
```
