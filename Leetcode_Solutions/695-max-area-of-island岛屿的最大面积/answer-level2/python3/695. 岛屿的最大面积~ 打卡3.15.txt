### 解题思路
BFS大发好！！
### 代码

```python3
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        row = len(grid)
        col = len(grid[0])

        directions = [(-1, 0), (1, 0), (0, 1), (0, -1)]

        def bfs(i, j):
            queue = [(i, j)]
            area = 0
            while queue:
                cur_i, cur_j = queue.pop(0)
                area += 1
                for dx, dy in directions:
                    next_i = cur_i + dx
                    next_j = cur_j + dy
                    if next_i in range(0, row) and next_j in range(0,col) and grid[next_i][next_j]:
                        grid[next_i][next_j] = 0
                        queue.append((next_i, next_j))
            return area
        ans = 0
        for i in range(row):
            for j in range(col):
                if grid[i][j] == 1:
                    grid[i][j] = 0
                    area = bfs(i, j)
                    ans = max(ans, area)
        return ans
                    

        
```