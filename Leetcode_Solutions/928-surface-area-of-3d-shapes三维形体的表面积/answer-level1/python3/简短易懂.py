```
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        #每一个网格的表面积的和-相重合的面积
        num = 0        
        for i in range(0,len(grid)):
            for j in range(0,len(grid)):
                if grid[i][j] != 0: # 一开始没有这个if，导致0个方块也有面积
                    num = num + 4*grid[i][j] + 2               
                if j > 0:
                    num -= 2*min(grid[i][j],grid[i][j-1])
                if i > 0:
                    num -= 2*min(grid[i][j],grid[i-1][j])
        return num

```



