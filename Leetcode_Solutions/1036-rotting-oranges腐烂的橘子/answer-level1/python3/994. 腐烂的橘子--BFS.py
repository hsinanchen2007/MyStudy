### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        row , col, time = len(grid), len(grid[0]), 0
        directions = [(0,1), (0,-1), (1,0), (-1,0)]
        queue = [(i, j, 0) for i in range(row) for j in range(col) if grid[i][j] == 2]
        while queue:
            i, j, time = queue.pop(0)
            for di, dj in directions:
                if 0<=i+di<row and 0<=j+dj<col and grid[i+di][j+dj]==1:
                    grid[i+di][j+dj] = 2
                    queue.append((i+di, j+dj, time+1))
        for i in grid:
            if 1 in i: return -1
        return time

```