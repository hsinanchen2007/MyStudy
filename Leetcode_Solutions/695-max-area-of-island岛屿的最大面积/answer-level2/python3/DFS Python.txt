### 解题思路
求岛屿最小个数的代码直接移植过来改一下count的机制就可以，就是两道题列表元素一个是int一个str需要注意判断条件，debug半天= =

### 代码

```python
class Solution(object):
    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if not grid:
            return 0
        n = len(grid)-1 #行数(0-n)
        m = len(grid[0])-1 #列数(0-m)
        area = 0
        
        def zero(i,j):
            if grid[i][j] == 0:
                return 0
            grid[i][j] = 0
            return (zero(i-1, j) if i>0 else 0) + (zero(i, j-1) if j>0 else 0)\
            + (zero(i+1, j) if i<n else 0) + (zero(i, j+1) if j<m else 0) + 1
                
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 0:
                    continue
                else:
                    area = max(area, zero(i,j))
                    #print(grid)
        return area
```