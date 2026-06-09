### 解题思路
1. 记录每一行的1的位置
2. 求交集的长度

### 代码

```python3
class Solution:
    def countCornerRectangles(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0

        N, M = len(grid), len(grid[0])
        cols = collections.defaultdict(set)
        for r in range(N):
            for c in range(M):
                if grid[r][c] == 1:
                    cols[r].add(c)

        ans = 0
        cols = list(cols.values())
        ncols = len(cols)
        for i in range(ncols):
            for j in range(i+1, ncols):
                s = len(cols[i].intersection(cols[j]))
                ans += s * (s - 1) // 2

        return ans
```