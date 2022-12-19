## 思路

遍历所有的位置，遇到1则作为起点开始深度优先遍历，同时将遍历过的地方置为0，维护最大的值返回

## 代码
```python
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        self.grid = grid
        self.m = len(grid)
        if self.m == 0:
            return 0
        self.n = len(grid[0])
        max_ = 0
        self.temp = 0
        for i in range(self.m):
            for j in range(self.n):
                if grid[i][j] == 1:
                    self._dfs(i, j)
                    max_ = max(max_, self.temp)
                    self.temp = 0
        return max_


    def _dfs(self, i, j):
        if self.is_ok(i, j):
            self.temp += 1
            self.grid[i][j] = 0
            self._dfs(i, j -1)
            self._dfs(i, j+1)
            self._dfs(i-1, j)
            self._dfs(i+1, j)


    def is_ok(self, i, j):
        return i >= 0 and i < self.m  and j >= 0 and j < self.n and self.grid[i][j] == 1
```