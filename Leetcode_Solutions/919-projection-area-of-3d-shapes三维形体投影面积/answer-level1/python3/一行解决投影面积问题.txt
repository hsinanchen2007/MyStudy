### 解题思路
分别计算三种投影面积，进行求和。其中yz部分计算比较复杂

### 代码

```python3
class Solution:
    def projectionArea(self, grid: List[List[int]]) -> int:
        return sum(list(max(i) for i in grid)) + sum(sum(list(1 if j else 0 for j in i)) for i in grid) + sum(list(max(list(grid[i][j] for i in range(len(grid)))) for j in range(len(grid[0]))))
```