### 解题思路
在大神的指点下，只需小计算北边和西边的边长就可以，但是看成绩，感觉还有更好的方法

### 代码

```python3
class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        length=len(grid)
        width=len(grid[0])
        b=0
        x=0
        for i in range(length):
            for j in range(width):
                if grid[i][j]==1 and (grid[i-1][j]!=1 if i>0 else True):
                    b=b+1
                if grid[i][j]==1 and  (grid[i][j-1]!=1 if j>0 else True):
                    x=x+1
        return 2*(b+x)
```