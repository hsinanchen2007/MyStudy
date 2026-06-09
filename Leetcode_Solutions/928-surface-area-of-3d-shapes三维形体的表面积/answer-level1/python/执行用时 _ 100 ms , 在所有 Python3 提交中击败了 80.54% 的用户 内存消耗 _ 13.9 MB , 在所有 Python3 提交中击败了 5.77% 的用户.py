### 解题思路
先得到立方体总数，再计算总数的立方体应有的表面积，最后减去行和列的重叠的部分

### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        v = 0
        for i in range(len(grid)):
            v += sum(grid[i]) # 得到立方体总数
        if len(grid) == 0:
            return 0
        elif len(grid) == 1 and len(grid[0]) == 1:
            s = 6 * v - (v - 1) * 2
        else:
            s = 0
            s1 = 0
            s2 = 0
            for i in range(len(grid)):
                for j in range(len(grid[i])):
                    if grid[i][j] != 0:
                        s += 6 * grid[i][j] - (grid[i][j] - 1) * 2
                    if i > 0:
                        s1 += 2 * min(grid[i-1][j],grid[i][j])
                    if j > 0:
                        s2 += 2 * min(grid[i][j],grid[i][j-1])
            s = s-s1-s2
        return s        
```