暴力
```
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        count = 0 
        for i in range(m):
            for j in range(n):
                if grid[i][j] < 0:
                    count += 1
        return count
```
