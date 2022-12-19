```python
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        res = 0
        self.m = len(grid)
        if self.m == 0: return 0
        self.n = len(grid[0])
        for i in range(self.m):
            for j in range(self.n):
                if grid[i][j] == "1":
                    self.dfs(grid,i,j)
                    res += 1
        return res
    def dfs(self,grid,i,j):
        if i < 0 or j < 0 or i >= self.m or j >= self.n or grid[i][j] == "0":return
        grid[i][j] = "0"
        self.dfs(grid,i+1,j)
        self.dfs(grid,i-1,j)
        self.dfs(grid,i,j+1)
        self.dfs(grid,i,j-1)
```
执行用时 :148 ms, 在所有 Python3 提交中击败了90.93% 的用户
内存消耗 :13.7 MB, 在所有 Python3 提交中击败了90.23%的用户