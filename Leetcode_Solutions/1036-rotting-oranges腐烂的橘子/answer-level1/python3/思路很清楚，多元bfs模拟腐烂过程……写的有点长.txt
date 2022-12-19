### 解题思路
首先遍历把所有腐烂的水果放到队列里，
bfs遍历所有可能被腐烂的水果
额外放入队列的还有step
最后再遍历一遍原来的列表，如果还有未腐烂的水果，则返回-1
否则返回step的最大值。

visited_list的话，直接用grid就好了。

### 代码

```python3
import queue

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        q = queue.deque()
        m = len(grid)
        n = len(grid[0])

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 2:
                    q.appendleft((i,j,0))
                    grid[i][j] = 1

        max_step = 0
        while len(q) > 0:
            i,j,step = q.pop()
            if i < 0 or i >= m or j < 0 or j >= n:
                continue
            if grid[i][j]==2 or grid[i][j] == 0:
                continue
            if grid[i][j] == 1:
                max_step = max(max_step, step)
                q.appendleft((i+1,j,step+1))
                q.appendleft((i-1,j,step+1))
                q.appendleft((i,j+1,step+1))
                q.appendleft((i,j-1,step+1))
                grid[i][j] = 2

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    return -1

        return max_step
```