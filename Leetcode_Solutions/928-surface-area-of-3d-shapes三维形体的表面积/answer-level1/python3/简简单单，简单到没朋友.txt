### 解题思路
按照时间顺序摆放就行

### 代码

```python3
class Solution:
    def surfaceArea(self, grid) -> int:
        res = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 0:
                    continue
                res += grid[i][j] * 6 - grid[i][j] * 2 + 2
                if i - 1 >= 0 and grid[i-1][j] != 0:
                    res -= min(grid[i][j], grid[i-1][j]) * 2
                if j - 1 >= 0 and grid[i][j-1] != 0:
                    res -= min(grid[i][j], grid[i][j-1]) * 2
        return res
        
```