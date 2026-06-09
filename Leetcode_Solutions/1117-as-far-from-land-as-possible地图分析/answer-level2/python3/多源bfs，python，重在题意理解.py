```
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        from collections import deque
        queue=deque()
        visited=set()
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]==1:
                    queue.append((i,j))
                    visited.add((i,j))

        if len(queue)==0 or len(queue)==len(grid)*len(grid[0]):
            return -1
        directions=[(-1,0),(1,0),(0,1),(0,-1)]
        res=-1

        def Is(x,y):
            return x>=0 and x<len(grid) and y>=0 and y<len(grid)

        while queue:
            res+=1
            n=len(queue)
            for _ in range(n):
                x,y=queue.popleft()
                for direction in directions:
                    new_x=x+direction[0]
                    new_y=y+direction[1]
                    if Is(new_x,new_y) and (new_x,new_y) not in visited:
                        visited.add((new_x,new_y))
                        queue.append((new_x,new_y))
        return res

```
