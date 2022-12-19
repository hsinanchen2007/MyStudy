### 解题思路

### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        s = 0
        for i in range(0, len(grid)):
            for j in range(0, len(grid[i])):
                if grid[i][j]: s += grid[i][j]*4+2
                for di, dj in [[-1, 0], [1, 0], [0, -1], [0, 1]]:
                    if i+di>=0 and i+di<len(grid) and j+dj>=0 and j+dj<len(grid[i]):
                        s -= min(grid[i+di][j+dj], grid[i][j])
        return s


        
        
```