```
class Solution:
    def surfaceArea(self, grid):
        count=0
        for i in range(len(grid)):
            for j in range(len(grid)):
                count+=grid[i][j]*6
                if grid[i][j]>=2:
                    count-=(grid[i][j]-1)*2
                if i :
                    count-=min(grid[i][j],grid[i-1][j])*2
                if j :
                    count-=min(grid[i][j],grid[i][j-1])*2
        return  count
a=Solution()
grid=[[2]]
print(a.surfaceArea(grid))
```
