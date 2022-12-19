### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    # 上右下左4个方向
    directions = [[-1, 0], [0, 1], [1, 0], [0, -1]]
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        if not grid and not grid[0]:
            return -1
        m = len(grid)
        n = len(grid[0])
        # 使用marked数组
        marked = [[0] * n for i in range(m)]
        res = 0
        for i in range(m):
            for j in range(n):
                if marked[i][j] == 0 and grid[i][j] == 1:
                    res = max(self.dfs(grid, i, j, m, n, marked), res)
        return res
    def dfs(self, grid, i, j, m, n, marked):
        res = 1
        # 标记marked数组
        marked[i][j] = 1
        for di_x, di_y in self.directions:
            row = i + di_x
            col = j + di_y
            # 如果未使用
            if 0 <= row < m and 0 <= col < n and marked[row][col] == 0 and grid[row][col] == 1:
                res += self.dfs(grid, row, col, m, n, marked)
        return res 
```