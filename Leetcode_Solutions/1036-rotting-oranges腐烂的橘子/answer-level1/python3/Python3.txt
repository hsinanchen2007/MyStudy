### 解题思路

BFS

### 代码

```python3
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        def bfs():
            day = -1
            while queue:
                day += 1
                level = len(queue)
                for _ in range(level):
                    row, col = queue.popleft()
                    for x, y in [(-1,0), (1,0), (0,-1), (0,1)]:
                        if 0<= row+x <m and 0<= col+y <n:
                            if not visit[row+x][col+y] and grid[row+x][col+y]==1:
                                visit[row+x][col+y] = True
                                grid[row+x][col+y] = 2
                                queue.append((row+x, col+y))
            return day
   
        from collections import deque
        if not grid:
            return 0
        m, n = len(grid), len(grid[0])
        queue = deque([])
        visit = [[False] * n for _ in range(m)]
        # 所有腐烂橘子同时开始扩散
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 2:
                    visit[i][j] = True
                    queue.append((i, j))
        day = bfs()   
        
        # 判断是否全都腐烂,没有全部腐烂, 输出-1
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    return -1
        # day==-1, 说明没有腐烂的橘子, 队列为空,上一步排除了1的情况,说明此时grid中都是0或2
        if day == -1:
            return 0
        return day
```