### 解题思路


### 代码

```python3
from collections import deque
class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        if not grid:
            return 

        count=0
        m, n = len(grid), len(grid[0])

        def BFS(i, j):
            flag=True
            queue=deque()
            queue.appendleft((i,j))
            while queue:
                i,j = queue.pop()
                grid[i][j]=1
                for x,y in [(-1,0),(1,0),(0,1),(0,-1)]:
                    new_i=i+x
                    new_j=j+y
                    if new_i>=m or new_i<0 or new_j>=n or new_j<0:
                        flag=False
                    elif grid[new_i][new_j]==0:
                        queue.appendleft((new_i, new_j))
            return flag

        def DFS(i, j):
            grid[i][j]=1
            for x,y in [(-1,0),(1,0),(0,1),(0,-1)]:
                new_i=i+x
                new_j=j+y
                if new_i>=m or new_i<0 or new_j>=n or new_j<0:
                    self.flag=False
                elif grid[new_i][new_j]==0:
                    DFS(new_i, new_j)

        for i in range(m):
            for j in range(n):
                # if grid[i][j]==0 and BFS(i, j):
                #     count+=1
                if grid[i][j]==0:
                    self.flag=True
                    DFS(i, j)
                    if self.flag:
                        count+=1
        return count
```