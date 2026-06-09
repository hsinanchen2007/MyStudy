### 解题思路
将所有陆地放入一个队列中，对队列中的每一个点向外搜索，如果遇到海洋就把海洋格子标记为来过，并将海洋格子加入队列，下次对队列中的点进行搜索直到队列为空
### 代码

```python3
from collections import deque
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        #思路：将所有的陆地放入队列中进行BFS
        n = len(grid)
        que = deque()
        for x in range(n):
            for y in range(n):
                if grid[x][y] == 1:
                    que.append((x,y))
        if n == 0 or len(que) == n**2:
            return -1
        step = 0 
        while que:
            step += 1
            for _ in range(len(que)):
                x,y = que.pop()
                for i,j in [(x+1,y),(x-1,y),(x,y+1),(x,y-1)]:
                    if i >= 0 and i < n and j >= 0 and j < n and grid[i][j] == 0:
                        grid[i][j] = -1
                        que.appendleft((i,j))
        return step -1 

        
```