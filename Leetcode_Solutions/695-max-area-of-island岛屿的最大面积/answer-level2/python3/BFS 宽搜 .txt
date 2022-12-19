### 解题思路
此处撰写解题思路
维护一个visited记录是否访问过坐标(i,j)
从每一个新的(i,j)出发 进入queue 
cur作为从(i,j)出相连的岛的点数
首先初始化为0 ，当遇到新的点并且坐标值为1时cur+=1
### 代码

```python3
class Solution:
    def maxAreaOfIsland(self, grid):
        from collections import deque
        m,n = len(grid),len(grid[0])
        visited = {}
        directions = [(-1,0),(1,0),(0,1),(0,-1)]
        queue = deque()
        res = 0
        for i in range(m):
            for j in range(n):
                cur = 0
                if (i,j) not in visited and grid[i][j]==1:
                    queue.append((i,j))
                    visited[(i,j)]= True
                    cur = 1
                while queue:
                    x,y = queue.popleft()
                    for dx,dy in directions:
                        nx,ny = x+dx,y+dy
                        if self.is_valid(nx,ny,grid,visited):
                            cur += 1
                            queue.append((nx,ny))
                            visited[(nx,ny)]=True
                res = max(res,cur)
        return res
    
    def is_valid(self,x,y,grid,visited):
        if 0<=x<len(grid) and 0<=y<len(grid[0]) and grid[x][y]==1 and (x,y) not in visited:
            return True
        return False

```