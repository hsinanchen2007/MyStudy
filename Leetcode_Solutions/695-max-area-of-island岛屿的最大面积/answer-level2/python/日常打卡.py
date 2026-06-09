### 解题思路
依次遍历，将遍历过的节点标记，避免重复标记

### 代码

```python3
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:

        maxArea = 0

        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == 1:
                    self.currArea = 0
                    self.addArea(grid,i,j)
                    maxArea = self.currArea if self.currArea > maxArea else maxArea
        return maxArea

    def addArea(self, grid, i, j):
        if 0 <=i < len(grid) and 0 <= j < len(grid[i]):
            if grid[i][j] == 1:
                self.currArea += 1
                grid[i][j] = -1
                self.addArea(grid,i,j+1)
                self.addArea(grid,i,j-1)
                self.addArea(grid,i+1,j)
                self.addArea(grid,i-1,j)

```