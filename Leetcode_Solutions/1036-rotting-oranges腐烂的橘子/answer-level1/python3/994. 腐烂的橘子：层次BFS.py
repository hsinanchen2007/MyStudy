列表解析，集合实现。

```python []
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        q = {
            (i, j) 
            for i, j in itertools.product(range(m), range(n)) 
            if grid[i][j] == 2
        }
        d = ((0, 1), (1, 0), (0, -1), (-1, 0))
        ans = -bool(q)
        while q:
            q = {
                grid[x].__setitem__(y, 2) or (x, y)
                for (i, j), (di, dj) in itertools.product(q, d)
                if 0 <= (x := i + di) < m and 0 <= (y := j + dj) < n and grid[x][y] == 1
            }
            ans += 1
        return any(1 in g for g in grid) and -1 or ans
```
![image.png](https://pic.leetcode-cn.com/c7d6be0c3904a6939f69bcf6906ac88815d48d4263782323f1bb06a2342217e3-image.png)
