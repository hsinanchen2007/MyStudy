### 解题思路
借助了题解中广度优先的思路，不断扩展陆地，直到没有海洋。
（广度优先啥的咱也不懂！）

### 代码

```python3
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        n = 1
        isExpand = True
        while isExpand :
            isExpand = False
            for i in range(len(grid)):
                for j in range(len(grid)):
                    if grid[i][j] == n:
                        isExpand = (self.expand(i, j, n + 1, grid) or isExpand)
            if isExpand:
                n += 1
        return -1 if n == 1 else n - 1

    
    def expand(self, i, j, n, grid):
        left = self.expandLeft(i-1, j, n, grid)
        top = self.expandTop(i, j-1, n, grid)
        right = self.expandRight(i+1, j, n, grid)
        bottom = self.expandBottom(i, j+1, n, grid)
        return (left or top or right or bottom)

    def expandLeft(self, i, j, n, grid):
        if i >= 0:
            if grid[i][j] == 0 :
                grid[i][j] = n
                return True
        return False

    def expandTop(self, i, j, n, grid):
        if j >= 0:
            if grid[i][j] == 0 :
                grid[i][j] = n
                return True
        return False

    def expandRight(self, i, j, n, grid):
        if i < len(grid):
            if grid[i][j] == 0 :
                grid[i][j] = n
                return True
        return False

    def expandBottom(self, i, j, n, grid):
        if j < len(grid):
            if grid[i][j] == 0 :
                grid[i][j] = n
                return True
        return False
```