### 解题思路
        N=len(grid[0]) #网格长宽
        n=0 #正方体个数
        z=0 #竖直方向上的重叠面
        x_y=0 #水平方向上的重叠面

### 代码

```python
class Solution(object):
    def surfaceArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        N=len(grid[0]) #网格长宽
        n=0 #正方体个数
        z=0 #竖直方向上的重叠面
        x_y=0 #水平方向上的重叠面
        for i in range (N):
            for j in range(N):
                n+=grid[i][j]
                if grid[i][j]>=2:
                    z+=grid[i][j]-1
                if j!=N-1:
                    x_y+=min(grid[i][j],grid[i][j+1])
                    x_y+=min(grid[j][i],grid[j+1][i])
        sum=6*n-2*(x_y+z)
        return sum
```