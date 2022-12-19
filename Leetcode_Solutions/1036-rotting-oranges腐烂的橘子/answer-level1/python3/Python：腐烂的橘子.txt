### 解题思路
BFS
copy，完成任务
原作者写的真好

### 代码

```python3
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        from collections import deque
        directions = [(-1,0),(1,0),(0,-1),(0,1)]
        m,n,time = len(grid),len(grid[0]),0
        result = deque()
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 2:
                    result.append((i,j,time))
        while result:
            x,y,time = result.popleft()
            for direction in directions:
                x_new,y_new = x+direction[0],y+direction[1]
                if 0 <= x_new < m and 0 <= y_new < n and grid[x_new][y_new] == 1:
                    grid[x_new][y_new] = 2
                    result.append((x_new,y_new,time+1))
        for row in grid:
            if 1 in row:
                return -1
        return time 
```