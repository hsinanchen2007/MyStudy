```
class Solution(object):
    def maxAreaOfIsland(self, grid):
        row = len(grid)
        low = len(grid[0])
        rs = 0
        for i in range(row):
            for j in range(low):
                if grid[i][j] == 1:
                    temp = self.getArea(i,j,grid)
                    rs = max(rs, temp)

        pass

    def getArea(self, i, j, grid):
        if i<0 or i>=len(grid) or j<0 or j>=len(grid[0]) or grid[i][j]==0:
            return 0
        rs = 1
        grid[i][j] = 0

        rs += self.getArea(i-1, j, grid)
        rs += self.getArea(i+1, j, grid)
        rs += self.getArea(i, j-1, grid)
        rs += self.getArea(i, j+1, grid)

        return rs
```
