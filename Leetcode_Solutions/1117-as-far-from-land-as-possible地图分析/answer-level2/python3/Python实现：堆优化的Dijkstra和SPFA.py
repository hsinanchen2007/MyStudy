### 解题思路
Dijkstra用于求有权图中的最短路径，对于无权图，Dijkstra跟BFS是一致的。另外堆优化的Dijkstra算法和SFPA算法在思想上并无太大区别。

### 代码
#### 堆优化的Dijkstra
```python3
import heapq
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        n = len(grid)
        d = [[float('inf')]*n for _ in range(n)]
        priority_queue = []
        directions = [(-1,0),(1,0),(0,-1),(0,1)]

        def isValid(x,y):
            if x < 0 or x >= n or y < 0 or y >= n:return False
            return True
        
        for i in range(n):
            for j in range(n):
                if grid[i][j]:#->island
                    d[i][j] = 0
                    heapq.heappush(priority_queue,[0,i,j])
        
        while priority_queue:
            step,x,y = heapq.heappop(priority_queue)
            for dx,dy in directions:
                next_x,next_y = x + dx, y + dy
                if isValid(next_x,next_y) and d[next_x][next_y] > step + 1:
                    d[next_x][next_y] = step + 1
                    heapq.heappush(priority_queue,[step+1,next_x,next_y])
                    
        ans = -1
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 0:ans = max(ans,d[i][j])

        return ans if ans != float('inf') else -1
```

#### SPFA
```python3
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        n = len(grid)
        d,inQueue = [[float('inf')]*n for _ in range(n)],[[False]*n for _ in range(n)]
        queue = []
        directions = [(-1,0),(1,0),(0,-1),(0,1)]

        def isValid(x,y):
            if x < 0 or x >= n or y < 0 or y >= n:return False
            return True
        
        for i in range(n):
            for j in range(n):
                if grid[i][j]:#->island
                    d[i][j] = 0
                    queue.append([i,j])
                    inQueue[i][j] = True
        
        while queue:
            x,y = queue.pop(0)
            for dx,dy in directions:
                next_x,next_y = x + dx, y + dy
                if isValid(next_x,next_y) and d[next_x][next_y] > d[x][y] + 1:
                    d[next_x][next_y] = d[x][y] + 1
                    if not inQueue[next_x][next_y]:
                        queue.append([next_x,next_y])
                        inQueue[next_x][next_y] = True
                    
        ans = -1
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 0:ans = max(ans,d[i][j])

        return ans if ans != float('inf') else -1
```