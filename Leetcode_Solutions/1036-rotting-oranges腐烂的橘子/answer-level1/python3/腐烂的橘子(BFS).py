### 解题思路
先找出烂橘子位置和好橘子数量，然后广度优先搜索

### 代码

```python
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        queue = []
        count = 0
        for r in range(m):
            for c in range(n):
                if grid[r][c] == 2:
                    queue.append((r, c))
                elif grid[r][c] == 1:
                    count += 1
        round_ = 0
        while len(queue) > 0 and count > 0:
            round_ += 1
            l = len(queue)
            for i in range(l):
                r, c = queue.pop(0)
                if r - 1 >= 0 and grid[r-1][c] == 1:
                    grid[r-1][c] = 2
                    count -= 1
                    queue.append((r-1, c))
                if c - 1 >= 0 and grid[r][c-1] == 1:
                    grid[r][c-1] = 2
                    count -= 1
                    queue.append((r, c-1))
                if r + 1 < m and grid[r+1][c] == 1:
                    grid[r+1][c] = 2
                    count -= 1
                    queue.append((r+1, c))
                if c + 1 < n and grid[r][c+1] == 1:
                    grid[r][c+1] = 2
                    count -= 1
                    queue.append((r, c+1))
        if count > 0:   return -1
        return round_


```