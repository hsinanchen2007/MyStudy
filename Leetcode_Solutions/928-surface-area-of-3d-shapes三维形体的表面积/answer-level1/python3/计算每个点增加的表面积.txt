### 解题思路
每个点如果高度大于零，则上下两个面必定有，结果加2。
然后前后左右遍历，遇到比它矮的或者超出边界则再加超出的部分。

### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        n=len(grid)
        directions=[(1,0),(-1,0),(0,1),(0,-1)]
        res=0
        for i in range(n):
            for j in range(n):
                if grid[i][j]==0:
                    continue
                res+=2
                for dx,dy in directions:
                    x=i+dx
                    y=j+dy
                    if 0<=x<n and 0<=y<n:
                        if grid[x][y]<grid[i][j]:
                            res+=grid[i][j]-grid[x][y]
                    else:
                        res+=grid[i][j]
        return res

                
```