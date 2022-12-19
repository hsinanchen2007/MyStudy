### 解题思路
先算单柱子并累加，再减去侧面重叠

### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        acc = 0
        for row,data_row in enumerate(grid):
            for col,val in enumerate(data_row):
                acc += val * 4 + 2 if val > 0 else 0
                if row:
                    acc -= 2 * min(val,grid[row-1][col])
                if col:
                    acc -= 2 * min(val,grid[row][col-1])
        return acc
```