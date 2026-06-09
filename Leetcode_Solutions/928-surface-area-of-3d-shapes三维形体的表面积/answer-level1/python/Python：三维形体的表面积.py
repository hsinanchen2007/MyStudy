### 解题思路
为什么是简单呢?!
我觉得好难啊！
暴力计算：
算每一个格子最终的表面积，加起来

### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        area=0
        row=len(grid)
        column=len(grid[0])
        for i in range(row):
            for j in range(column):
                k=grid[i][j]
                if k==0:continue 
                elif k==1:area=area+k*6
                else: area=area+k*4+2
                if i-1>-1: area-=min(k,grid[i-1][j])
                if i+1<row: area-=min(k,grid[i+1][j])
                if j-1>-1: area-=min(k,grid[i][j-1])
                if j+1<column: area-=min(k,grid[i][j+1])
        return area
```