### 解题思路
cur_hi=grid[i][j]
- 0.遍历所有的位置
- 1.对于顶面&底面的表面积，若cur_hi>0,则顶面和底面贡献共2个表面积；
- 2.对于侧面，只有在相邻的位置的高度(nhi)小于cur_hi时，对应的面才会贡献`max(cur_hi-nhi,0)`的表面积。

### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        M=len(grid)#row
        N=len(grid[0])#colume
        res=0#restore the result of the surface area
        for row in range(M):#
            for col in range(N):#scan all places
                if grid[row][col]:#if exits any body,calculate the 
                    res+=2# uppersurface+lowersurface
                    for nr,nc in [(row-1,col),(row+1,col),(row,col-1),(row,col+1)]:#judge any nbr.of grid[row][col]
                        if 0<=nr<M and 0<=nc<N:#(if nbrs. exit)
                            nhi=grid[nr][nc]#calculate the nbr's height
                        else:#(nbrs. do not exit)
                            nhi=0
                        res+=max(grid[row][col]-nhi,0)#if nbr exit, currnet result add the max item b/w 0 and cur_hi-neighbor_hi
        return res


```