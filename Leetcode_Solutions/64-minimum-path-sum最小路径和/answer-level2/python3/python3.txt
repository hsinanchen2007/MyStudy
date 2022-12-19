```
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        r = len(grid)
        c = len(grid[0])
        res = [ ['*' for i in range(c)] for i in range(r)]
        res[0][0] = grid[0][0] # 从第一个开始
        for i in range(1,c):   # 第一行递增
            res[0][i] = grid[0][i] + res[0][i-1]
        for i in range(1,r):   # 第一列递增
            res[i][0] = grid[i][0] + res[i-1][0]
        for i in range(1,r):
            for j in range(1,c):
                res[i][j] = min(res[i-1][j], res[i][j-1]) + grid[i][j]
        return res[-1][-1]
```
