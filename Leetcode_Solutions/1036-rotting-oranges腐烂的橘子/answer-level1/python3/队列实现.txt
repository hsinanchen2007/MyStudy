```
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        
        m = len(grid)
        n = len(grid[0])
        dr = [(1,0),(-1,0),(0,1),(0,-1)]
        
        #腐烂的橘子队列
        queue = []
        for i in range(m):
            for j in range(n):
                if grid[i][j]==2:
                    queue.append((i,j))
        time = 0
        while queue:
            for t in range(len(queue)):
                i,j = queue.pop(0)
                for d in dr:
                    x=i+d[0]
                    y=j+d[1]
                    if 0<=x<m and 0<=y<n and grid[x][y]==1:
                        grid[x][y]=2
                        queue.append((x,y))
            time+=1
        for i in range(m):
            for j in range(n):
                if grid[i][j]==1:
                    return -1
        return 0 if time==0 else time-1
```
