### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
   
        rows = len(grid)
        if not rows:
            return -1
        cols = len(grid[0])
        time = 0
        queue = [(i, j, time) for i in range(rows) for j in range(cols) if grid[i][j] == 2]
        direction = [(0, -1), (-1, 0), (0, 1), (1, 0)]
        while queue:
            x, y, time = queue.pop(0)
            for direc in direction:
                new_x, new_y = x + direc[0], y + direc[1]
                if 0 <= new_x < rows and 0 <= new_y < cols and grid[new_x][new_y] == 1:
                    grid[new_x][new_y] = 2
                    queue.append((new_x, new_y, time+1))
        for row in grid:
            if 1 in row:
                return -1
        return time
```