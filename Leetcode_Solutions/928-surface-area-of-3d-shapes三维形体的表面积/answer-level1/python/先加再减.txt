### 解题思路
针对每个单元格，先对其上的立方体的表面积进行累加，然后再根据其周边的立方体的情况，将重叠的无效表面积减去。
重叠的无效表面积计算方法如下：
min(v,grid[i-1][j])*2*(i>0) + min(v,grid[i][j-1])*2*(j>0)

### 代码

```python
class Solution(object):
    def surfaceArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        N = len(grid)
        ans = 0
        for i in range(N):
            for j in range(N):
                v = grid[i][j]
                orig = 0
                if v:
                    orig = 6*v-(v-1)*2
                ans += orig - (min(v,grid[i-1][j])*2*(i>0)+min(v,grid[i][j-1])*2*(j>0))
        return ans
```