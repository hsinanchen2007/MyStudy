```python
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        # v个叠在一起的正方体组成的长方体表面积为 v*4 + 2
        # 相邻的高度为m、n的正方体，重叠的表面积为min(m, n) * 2
        # 用所有长方体不重叠的表面积，减去所有重叠的表面积，既是答案
        total = 0
        covered = 0
        height = len(grid)
        if height == 0:
            return 0
        length = len(grid[0])
        for i in range(height):
            for j in range(length):
                # v=0 时，对total和covered都没有影响
                if grid[i][j] == 0:
                    continue
                total += grid[i][j] * 4 + 2
                # 只计算右、下的重叠面积，避免重复计算
                if i + 1 < height:
                    covered += min(grid[i][j], grid[i+1][j]) * 2
                if j + 1 < length:
                    covered += min(grid[i][j], grid[i][j+1]) * 2
        return total - covered
```