### 解题思路
从左上角开始，原地修改，grid[i][j] +=min(grid[i-1][j],grid[i][j-1])

### 代码

```python3
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0        
        m = len(grid);n=len(grid[0])
        for j in range(1,n):
            grid[0][j] +=grid[0][j-1]
        for i in range(1,m):
            grid[i][0] += grid[i-1][0]
        for i in range(1,m):
            for j in range(1,n):
                grid[i][j] +=min(grid[i-1][j],grid[i][j-1])
        return grid[-1][-1]

```