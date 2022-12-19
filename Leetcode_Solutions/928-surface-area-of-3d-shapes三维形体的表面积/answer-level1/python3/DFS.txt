```
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        def surface(nums):
            if nums==0:
                return 0
            return 6*nums-(nums-1)*2
        import numpy as np
        searched=np.zeros((len(grid),len(grid)))
        def DFS(gird,i,j):
            #边界条件
            if  searched[i][j]:
                return 0
            tsurfase=surface(gird[i][j])
            #print(tsurfase)
            searched[i][j]=1
            for newi,newj in [(-1,0),(1,0),(0,-1),(0,1)]:
                #当前为空的情况也考虑进去
                if tsurfase and newi+i>=0 and newi+i<len(grid) and (newj+j)>=0 \
                and (newj+j)<len(grid):
                    #减去公共部分
                    tsurfase-=min(grid[i][j],grid[newi+i][newj+j])
            for newi,newj in [(-1,0),(1,0),(0,-1),(0,1)]:
                if newi+i>=0 and newi+i<len(grid) and (newj+j)>=0 and (newj+j)<len(grid):
                    tsurfase+=DFS(gird,newi+i,newj+j)
            

            return tsurfase
        return DFS(grid,0,0)


            

```
