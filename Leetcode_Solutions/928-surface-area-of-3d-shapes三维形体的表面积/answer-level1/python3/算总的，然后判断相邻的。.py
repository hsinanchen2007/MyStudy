### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        res = 0
        for x in range(m) :
            for y in range(n):
                a = 0
                if grid[x][y] != 0:
                    a = grid[x][y] * 4 + 2
                    if y + 1 < n:
                        a -= min(grid[x][y+1], grid[x][y])
                    if y - 1 >= 0:
                        a -= min(grid[x][y-1], grid[x][y])
                    if x + 1 < m:
                        a -= min(grid[x+1][y], grid[x][y])
                    if x - 1 >= 0:
                        a -= min(grid[x-1][y], grid[x][y])
                print(a)
                res += a
        return res
```