### 解题思路
python

### 代码

```python
from itertools import chain

class Solution(object):
    def shiftGrid(self, grid, k):
        # 从二维到一维
        m=len(grid)
        n=len(grid[0])

        grid = list(chain(*grid))
        l_grid = len(grid)

        ## 在list后面添加相同的list

        k=k%l_grid
        grid = grid[l_grid-k:l_grid] +grid[0:l_grid-k]

        # 从二维到一维
        res=[]
        row=[]

        for i in range(m*n):
            if i>0 and i % n ==0:
                res.append(row)
                row=[]
            row.append(grid[i])
        res.append(row)
        return res

        """
        :type grid: List[List[int]]
        :type k: int
        :rtype: List[List[int]]
        """
```