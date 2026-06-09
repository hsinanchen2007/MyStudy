class Solution:
```
    def surfaceArea(self, grid: List[List[int]]) -> int:
            if not grid:
                return 0
            res = 0
            for i in range(len(grid)):
                for j in range(len(grid[0])):
                    res += 6 * grid[i][j]
                    if grid[i][j] > 1:
                        res -= 2 * (grid[i][j] - 1) 
                    if i - 1 >= 0 and grid[i - 1][j]:
                        res -= 2 * min(grid[i - 1][j], grid[i][j])
                    if j - 1 >= 0 and grid[i][j - 1]:
                        res -= 2 * min(grid[i][j - 1], grid[i][j])
            return res
```
    