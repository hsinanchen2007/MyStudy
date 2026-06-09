### 解题思路
广度遍历解题

### 代码

```python3
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        if len(grid[0])==0:
            return 0
        self.w = len(grid[0])
        self.h = len(grid)
        self.mm = 0
        for i in range(self.h):
            for j in range(self.w):
                m = 0
                m = self.findisland(i, j, grid, m)
                if m > self.mm:
                    self.mm =m
        return self.mm

    def findisland(self, i, j, grid, m):
        if grid[i][j] == 1:
            m+=1
            grid[i][j] = 0
            if i+1 < self.h:
                m = self.findisland(i+1, j, grid, m)                
            if j+1 < self.w:
                m = self.findisland(i, j+1, grid, m)
            if i-1 >= 0:
                m = self.findisland(i-1, j, grid, m)                
            if j-1 >= 0:
                m = self.findisland(i, j-1, grid, m)                
            return m
        else:
            return m

```