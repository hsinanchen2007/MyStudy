1. 每次的表面积就是 4 *（方块数） + 2，先加上再说。
2. 但是有重合部分，所以每次的位置上有方块时，还去除掉上边和左边的重叠部分，由于重叠部分在上一次计算表面积的时候就算过一次了，所以要除掉两次。
```python
class Solution(object):
    def surfaceArea(self, grid):
        res = 0
        for i in range(0, len(grid)):
            for j in range(0, len(grid[0])):
                if grid[i][j] > 0:
                    res += grid[i][j] * 4 + 2
                    if i-1 >= 0:
                        res -= min(grid[i][j], grid[i-1][j])*2
                    if j-1 >= 0:
                        res -= min(grid[i][j], grid[i][j-1])*2
        return res
```
时间复杂度O(n),空间复杂度O(1)