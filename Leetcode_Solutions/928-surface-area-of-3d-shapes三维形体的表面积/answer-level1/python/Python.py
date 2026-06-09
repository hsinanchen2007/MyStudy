### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        s = 0
        for i in range(len(grid)):
            for j in range(len(grid)):
                if grid[i][j] != 0:
                    if grid[i][j] != 0:
                        s += 4*grid[i][j] + 2
                    if i != 0:
                        s -= min(grid[i - 1][j], grid[i][j])*2
                    if j != 0:
                        s -= min(grid[i][j - 1], grid[i][j])*2
        return s
```