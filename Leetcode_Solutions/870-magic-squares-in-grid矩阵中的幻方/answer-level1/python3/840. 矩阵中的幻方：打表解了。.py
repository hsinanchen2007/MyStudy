40ms仅供参考。

```python
class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        d = collections.defaultdict(int)
        d.update({(8, 1, 6, 3, 5, 7, 4, 9, 2): 1, (2, 9, 4, 7, 5, 3, 6, 1, 8): 1, (8, 3, 4, 1, 5, 9, 6, 7, 2): 1, (4, 3, 8, 9, 5, 1, 2, 7, 6): 1, (6, 1, 8, 7, 5, 3, 2, 9, 4): 1, (6, 7, 2, 1, 5, 9, 8, 3, 4): 1, (2, 7, 6, 9, 5, 1, 4, 3, 8): 1, (4, 9, 2, 3, 5, 7, 8, 1, 6): 1})
        return sum(d[tuple(grid[i][j: j + 3] + grid[i + 1][j: j + 3] + grid[i + 2][j: j + 3])] for i in range(len(grid) - 2) for j in range(len(grid[0]) - 2))
```
