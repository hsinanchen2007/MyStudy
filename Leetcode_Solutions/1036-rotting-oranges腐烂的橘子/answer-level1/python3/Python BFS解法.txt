岛屿问题的变形。使用的方法类似

```
class Solution:

    # BFS 回溯法
    def orangesRotting(self, grid: List[List[int]]) -> int:
        # 定义四个方向
        locs = [[-1,0],[0,-1],[0,1],[1,0]] 
        stack = []
        m = len(grid)
        if m==0:
            return -1
        n = len(grid[0])
        time = 0 
        # visited = set()
        # 以腐烂的句子为起点，时间为0
        for i in range(m):
            for j in range(n):
                if grid[i][j]==2:
                    stack.append(((i,j,0)))
        # 使用栈
        while stack:
            i,j,time=stack.pop(0)
            # visited.add((i,j))
            for x_,y_ in locs:
                new_x,new_y = i+x_,j+y_
                if 0<=new_x<m and 0<=new_y<n and grid[new_x][new_y]==1:
                   grid[new_x][new_y] = 2
                   stack.append((new_x,new_y,time+1))
        
        for g in grid:
            if 1 in g:
                return -1
        return time

```
