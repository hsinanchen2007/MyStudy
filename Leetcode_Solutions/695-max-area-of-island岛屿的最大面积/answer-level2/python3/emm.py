```
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        max_area = 0 
        t = 0
        m = len(grid)
        n = len(grid[0])
        
        for i in range(m):
            if sum(grid[i])==0:
                continue
            for j in range(n):
                
                if grid[i][j]==1:
                    t+=1
                   
                else:
                    continue
                stack = [(i,j)]
                grid[i][j] = 0
                while stack:
                    x,y = stack.pop()
                    if x-1>=0 and grid[x-1][y]==1:
                        t+=1
                       
                        grid[x-1][y]=0
                        stack.append((x-1,y))
                    if y-1>=0 and grid[x][y-1]==1:
                        t+=1
                       
                        grid[x][y-1]=0
                        stack.append((x,y-1))
                    if x+1<m and grid[x+1][y]==1:
                        t+=1
                        
                        grid[x+1][y]=0
                        stack.append((x+1,y))
                    if y+1<n and grid[x][y+1]==1:
                        t+=1
                        
                        grid[x][y+1]=0
                        stack.append((x,y+1))
                max_area = max(max_area,t)
                t = 0
        return max_area
                    
                    
```
