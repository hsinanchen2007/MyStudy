### 解题思路


### 代码

```python3
from collections import deque
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        if not grid:
            return 

        m, n = len(grid), len(grid[0])
        maxArea=0


        def DFS(i, j):
            self.area+=1
            grid[i][j]=2
            for x,y in [(-1,0),(1,0),(0,1),(0,-1)]:
                new_i=i+x
                new_j=j+y
                if 0<=new_i<m and 0<=new_j<n and grid[new_i][new_j]==1:
                    DFS(new_i, new_j)

        def BFS(i, j):
            grid[i][j]=2
            queue=deque()
            queue.appendleft((i, j))
            while queue:
                i, j = queue.pop()
                self.area+=1
                for x,y in [(-1,0),(1,0),(0,1),(0,-1)]:
                    new_i=i+x
                    new_j=j+y
                    if 0<=new_i<m and 0<=new_j<n and grid[new_i][new_j]==1:
                        grid[new_i][new_j]=2
                        queue.appendleft((new_i, new_j))

        for i in range(m):
            for j in range(n):
                if grid[i][j]==1:
                    self.area=0
                    # DFS(i, j)
                    BFS(i, j)
                    maxArea=max(maxArea, self.area)
        return maxArea
```