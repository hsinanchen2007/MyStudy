### 解题思路
1. bfs
2. dfs
3. 并查集

### 代码

```python3
class Solution:

    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        # bfs
        if not grid:
            return 0
        m, n = len(grid), len(grid[0])
        visit = [[False] * n for _ in range(m)]
        
        def bfs(i, j):
            area, queue = 1, collections.deque([(i, j)])
            while queue:
                i, j = queue.popleft()
                for x, y in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                    if 0<= i + x < m and 0<= j+y < n:
                        if(grid[i+x][j+y] == 1 and not visit[i+x][j+y]):
                            area += 1
                            visit[i+x][j+y] = True
                            queue.append((i+x, j+y))
            return area
        
        area = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1 and not visit[i][j]:
                    visit[i][j] = True
                    area = max(area, bfs(i, j))
        return area
```