```
class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        zero_set=set()
        res=0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if not grid[i][j]==-1:
                    zero_set.add((i,j))
                if grid[i][j]==1:
                    start=(i,j)
                if grid[i][j]==2:
                    end=(i,j)
        def Is(x,y):
            return x>=0 and x<len(grid) and y>=0 and y<len(grid[0])
        
        directions=[(1,0),(0,1),(-1,0),(0,-1)]
        
        def backtrack(point,visited):
            nonlocal res
            if point==end and visited==zero_set:
                res+=1
                return 
            if point==end or visited==zero_set:
                return 
            for direction in directions:
                new_x=point[0]+direction[0]
                new_y=point[1]+direction[1]
                if Is(new_x,new_y) and (new_x,new_y) not in visited and not grid[new_x][new_y]==-1:
                    visited.add((new_x,new_y))
                    backtrack((new_x,new_y),visited)
                    visited.remove((new_x,new_y))

        backtrack(start,{start})
        return res
```
