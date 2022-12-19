**思路**：先计算每个断垣个独立的表面积（grid[i][j]*4+2）
          再减去相贴的面积（min(grid[i][j],grid[h][k])*2）
```
def surfaceArea(self, grid: List[List[int]]) -> int:
        res,sub=0,0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]!=0: #每个单元格独立的表面积
                    res+=(grid[i][j]*4+2)

                if grid[i][j]!=0 and 0<=i-1<len(grid) and grid[i-1][j]!=0:#需要减去的相贴的面积
                    sub+=min(grid[i][j],grid[i-1][j])
                if grid[i][j]!=0 and 0<=i+1<len(grid) and grid[i+1][j]!=0:
                    sub+=min(grid[i][j],grid[i+1][j])
                if grid[i][j]!=0 and 0<=j-1<len(grid[0]) and grid[i][j-1]!=0:
                    sub+=min(grid[i][j],grid[i][j-1])
                if grid[i][j]!=0 and 0<=j+1<len(grid[0]) and grid[i][j+1]!=0:
                    sub+=min(grid[i][j],grid[i][j+1])
        return res-sub
```
