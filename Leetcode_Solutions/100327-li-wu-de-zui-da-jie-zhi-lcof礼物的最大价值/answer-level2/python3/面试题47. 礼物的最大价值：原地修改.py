### 解题思路

动归入门题

### 代码

```python []
class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        for i, j in itertools.product(range(len(grid)), range(len(grid[0]))):
            grid[i][j] += max(i > 0 and grid[i - 1][j], j > 0 and grid[i][j - 1])
        return grid[-1][-1]
```