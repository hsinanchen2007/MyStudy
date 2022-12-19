```
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        
        result=0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]==0:
                    continue
                temp1=grid[i][j]*6-(grid[i][j]-1)*2
                for n in [[0,1],[1,0],[0,-1],[-1,0]]:
                    if 0<=i+n[0]<len(grid) and 0<=j+n[1]<len(grid[0]):
                        temp2=min(grid[i][j],grid[i+n[0]][j+n[1]])
                        temp1-=temp2
                result+=temp1
        
        return result
```
