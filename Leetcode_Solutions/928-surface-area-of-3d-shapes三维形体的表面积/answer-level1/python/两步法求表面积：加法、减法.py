思路：
1. 不考虑**不同网格**中方块的重叠，求各网格方块的面积（x*4+2）
2. 减去**不同网格**方块重叠的面积

```python
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        # import itertools
        # totol_area = sum(map(lambda x: x * 4 + 2 if x > 0 else 0, itertools.chain(*grid)))
        totol_area = 0
        for i in range(len(grid)):
            for j in range(len(grid)):
                if grid[i][j] > 0:
                    totol_area += grid[i][j] * 4 + 2
                if i > 0:
                    totol_area -= min(grid[i][j], grid[i-1][j]) * 2
                if j > 0:
                    totol_area -= min(grid[i][j], grid[i][j-1]) * 2
        return totol_area
```

注：

本来是用注释的两行来计算所有网格方块的面积和（通过chain将grid中的多个列表合成一个迭代器，参数通过``*``拆包，然后通过map,sum进行合并计算），后来发现还是要用循环，就索性放在循环里面计算了。

减去重合表面积，本来是判断四个方向（前后左右），后来发现只用判断两个方向（前左 或其它）