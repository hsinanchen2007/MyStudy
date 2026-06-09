### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        area = 0
        for i, row in enumerate(grid):
            for j, value in enumerate(row):
                if value > 0:
                    area += value * 4 + 2
                if j > 0:
                    area -= 2 * min(value, grid[i][j-1]) #同一行的前一个相交的面
                if i > 0:
                    area -= 2 * min(value, grid[i-1][j]) #前一行相交的面
        return area
          

```