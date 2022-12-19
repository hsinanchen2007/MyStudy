统计黏在一起的面一共有多少，然后总的面积减去该部分即可



```
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        count, total, N = 0, 0, len(grid)
        directions = [(0, 1), (1, 0)]
        for i in range(N):
            for j in range(N):
                total += grid[i][j]
                if grid[i][j] > 1: count += grid[i][j] - 1
                for dx, dy in directions:
                    x, y = i + dx, j + dy
                    if x < N and y < N:
                        count += min(grid[i][j], grid[x][y])
        return 6 * total - 2 * count    
```
