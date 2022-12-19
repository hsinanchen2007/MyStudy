## 思路:

思路一：朴素想法

看正方形周围是不是水，或者在边界处，这样才能产生周长

思路二：整体看

按行按列扫一遍即可

## 代码:

思路一：

```python
class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        row = len(grid)
        col = len(grid[0])
        res = 0
        for i in range(row):
            for j in range(col):
                if grid[i][j] == 1:
                    # 看四个方向 边界或者 邻居是水 周长 + 1
                    for x, y in [[-1, 0], [1, 0], [0, -1], [0, 1]]:
                        tmp_i, tmp_j = i + x, j + y
                        if  not (0 <= tmp_i < row and 0 <= tmp_j < col) or grid[tmp_i][tmp_j] == 0:
                            res += 1
                    
        return res
```

思路二：

```python
class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        return sum(
        sum(map(lambda x, y: x!=y, row + [0], [0] + row))
        for row in itertools.chain(grid, map(list, zip(*grid))))
```

