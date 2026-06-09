我们一层一层的计算面积, 并分别减去重叠的部分
首先计算每一个”柱子“的面积： `4*n + 2 if n > 0 else 0`
再把这一排的面积加起来 并减去这一层内的重叠部分
最后再减去曾与层之间的重叠面积

```python
    def surfaceArea(self, grid: List[List[int]]) -> int:
        surfaceSum = 0
        N = len(grid)
        for i in range(N):
            # 一排一排算
            surfaceSum += sum([4*n + 2 if n > 0 else 0 for n in grid[i]])
            # 层间重叠
            stack = 2 * sum([min(grid[i][j], grid[i][j-1]) for j in range(1, N)])
            surfaceSum -= stack
            # 在中间减去和前一排的重叠部分
            if i > 0:
                stack = 2 * sum([min(grid[i-1][j], grid[i][j]) for j in range(N)])
                surfaceSum -= stack
        return surfaceSum
```