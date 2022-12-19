```python
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        """可以用dfs做，也可以用并查集做，还是dfs吧，思路清晰一些"""
        self.grid = grid
        self.m = len(grid)
        self.n = len(grid[0])
        res = 0

        for i in range(self.m):
            for j in range(self.n):
                if self.grid[i][j] == 1:
                    res = max(res, self._dfs(i, j))

        return res

    def _dfs(self, i, j):
        if self._check_no_valid(i, j) or self.grid[i][j] != 1:
            return 0

        self.grid[i][j] = -1  # -1表示遍历过这个点了
        return 1 + self._dfs(i - 1, j) + self._dfs(i, j + 1) \
               + self._dfs(i + 1, j) + self._dfs(i, j - 1)

    def _check_no_valid(self, i, j):
        return i < 0 or i >= self.m or j < 0 or j >= self.n
```
