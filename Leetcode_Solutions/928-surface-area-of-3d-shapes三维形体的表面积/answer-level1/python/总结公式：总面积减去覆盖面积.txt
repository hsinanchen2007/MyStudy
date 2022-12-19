一个位置如果放置一摞正方体，比如有n个，那么覆盖的面就有2(n-1)个，因此，暴露的面积为 6n - 2(n-1) = 4n+2。
然而，两个相邻的位置放置正方体，也有有覆盖面产生，那么这时覆盖的面积为：较短的那一摞的高度hx2。
其实我们不用看一个位置的上下左右四个邻居，而只要看右边和下面邻居，并计算覆盖面乘以2就好。
```python
class Solution:
    directions = [(0, 1), (1, 0)]
    def checkAround(self, grid, i, j, m, n):
        substract = 0
        for di, dj in self.directions:
            i1, j1 = i + di, j + dj
            if 0 <= i1 < m and 0 <= j1 < n and grid[i1][j1]:
                substract += 2*min(grid[i1][j1], grid[i][j])
        return substract
            

    def surfaceArea(self, grid: List[List[int]]) -> int:
        m = len(grid)
        if m < 1:
            return 0
        n = len(grid[0])
        area = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j]:
                    area += 4*grid[i][j]+2 - self.checkAround(grid, i, j, m, n)
        return area
```
