### 解题思路
求m*n后遍历

### 代码

```python3
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        count = 0
        m = len(grid)
        n = len(grid[0])
        for i in range(m):
            for j in range(n):
                if grid[i][j] >= 0:
                    count += 1
        return m * n - count
```