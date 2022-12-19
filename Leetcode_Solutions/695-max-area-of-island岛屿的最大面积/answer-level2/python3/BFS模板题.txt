### 解题思路
我的代码清晰明了，非常简洁。

### 代码

```python3
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0
        areas = []
        visit = [[0 for _ in range(len(grid[0]))] for __ in range(len(grid))]
        steps = [[1, 0], [0, -1], [-1, 0], [0, 1]]      # 四个方向走

        def BFS(x, y):
            area = 1
            queue = [(x, y)]
            visit[x][y] = 1
            while queue:
                p = queue.pop(0)
                for i in steps:
                    dx, dy = p[0] + i[0], p[1] + i[1]
                    if 0 <= dx < len(grid) and 0 <= dy < len(grid[0]) and grid[dx][dy] == 1 and visit[dx][dy] == 0:
                        visit[dx][dy] = 1
                        area += 1
                        queue.append((dx, dy))
            areas.append(area)

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1 and visit[i][j] == 0:
                    BFS(i, j)
        return max(areas) if areas else 0
```