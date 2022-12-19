### 解题思路
多源BFS, 

### 代码

```python3
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        # 多源bfs, 最后入队的海洋就是最远海洋
        if not grid:
            return -1
        m, n = len(grid), len(grid[0])
        
        # 所有陆地作为起点
        from collections import deque
        queue = deque([(i, j) for i in range(m) for j in range(n) if grid[i][j]== 1])
        
        if len(queue) == m * n or len(queue) == 0:
            return -1
        
        # 最后加入队列的海洋就是最远海洋, 而且它也一定是由它最近的陆地先延伸到
        while queue:
            i, j = queue.popleft()
            for x, y in [(-1,0), (1,0), (0,-1), (0,1)]:
                if 0<= i + x < m and 0<= j + y < n and grid[i+x][j+y] == 0:
                    grid[i+x][j+y] = grid[i][j] + 1
                    queue.append((i+x, j+y))
        return grid[i][j]-1
```