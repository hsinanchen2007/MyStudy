### 解题思路
看注释就能懂

### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        result = 0
        length = len(grid)
        for i in range(length):
            for j in range(length):
                if grid[i][j]:
                    # 如果这个地方放了立方体，一定会有上下两个面积
                    result += 2
                    # 可能会挡住当前位置立方体表面积的无非是前后左右四个方向的立方体
                    for a, b in ((i- 1, j), (i + 1, j), (i, j - 1), (i, j + 1)):
                        # 如果这个方向上的立方体在网格内
                        if 0 <= a < length and 0 <= b < length:
                            # 如果比当前讨论位置的高度高，则当前讨论位置的立方体表面积会被遮住
                            # 如果比当前讨论位置的高度低，则就会相应漏出两者的高度差的表面积
                            if grid[a][b] < grid[i][j]:
                                result += grid[i][j] - grid[a][b]
                        # 如果不在内部，则全部一定不会被遮住
                        else:
                            result += grid[i][j]
        return result
```