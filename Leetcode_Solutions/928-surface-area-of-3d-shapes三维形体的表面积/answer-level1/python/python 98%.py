### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    
    def getAdj(self, r, c, RL, CL):
        return [(rx, cx) for rx, cx in [(r + 1, c), (r - 1, c), (r, c + 1), (r, c - 1)] if 0 <= rx < RL and 0 <= cx < CL]

    def surfaceArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        RL = len(grid)
        CL = len(grid[0])
        # top 
        totalArea = 0
        for r in range(RL):
            for c in range(CL):
                if grid[r][c] != 0:
                    selfArea = grid[r][c] * 4 + 2
                    shadowedArea = 0
                    for rx, cx in self.getAdj(r, c, RL, CL):
                        shadowedArea += min(grid[rx][cx], grid[r][c])
                    totalArea += (selfArea - shadowedArea)
        return totalArea

```