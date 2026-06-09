```
class Solution:
    def shortestDistance(self, grid: List[List[int]]) -> int:
        from collections import deque
        res=[]

        directions=[(0,1),(0,-1),(1,0),(-1,0)]

        def Is(x,y):
            return x>=0 and x<len(grid) and y>=0 and y<len(grid[0])

        #从每个建筑物（即1）出发，得到其到每个空地0的距离
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]==1:
                    queue=deque([(i,j)])
                    dis=-1
                    distance=[[float("inf")]*len(grid[0]) for _ in range(len(grid))]
                    distance[i][j]=0
                    visited=set((i,j))
                    while queue:
                        dis+=1
                        for _ in range(len(queue)):
                            x,y=queue.popleft()
                            for direction in directions:
                                new_x=x+direction[0]
                                new_y=y+direction[1]
                                if Is(new_x,new_y) and grid[new_x][new_y]==0 and (new_x,new_y) not in visited:
                                    visited.add((new_x,new_y))
                                    queue.append((new_x,new_y))
                                    distance[new_x][new_y]=dis+1
                    res.append(distance)
        n=len(res)
        minDis=float("inf")
        ########################选址###############################
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]==0:
                    minDis=min(minDis,sum(res[k][i][j] for k in range(n)))
        return minDis if minDis<float("inf") else -1
```
