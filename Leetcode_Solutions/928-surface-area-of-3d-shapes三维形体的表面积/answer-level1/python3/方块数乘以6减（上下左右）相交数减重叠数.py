方块数乘以6减（上下左右）相交数
```
class Solution:
    def surfaceArea(self, grid) -> int:
        c,k,n=0,0,len(grid)
        for i in range(n):
            for j in range(n):
                if grid[i][j]:
                    c+=grid[i][j]
                    k+=(grid[i][j]-1)*2
                    for _i,_j in [(1,0),(-1,0),(0,1),(0,-1)]:
                        ii,jj =i+_i,j+_j
                        if 0<=ii<n and 0<=jj<n:
                            k+=min(grid[i][j],grid[ii][jj])

        return c*6-k
```
