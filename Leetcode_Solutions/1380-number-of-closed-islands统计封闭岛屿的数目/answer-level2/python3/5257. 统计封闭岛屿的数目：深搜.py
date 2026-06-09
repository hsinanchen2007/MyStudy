![image.png](https://pic.leetcode-cn.com/caaf05302c2fc660ce8a1699b3683b8712cf094117ac2c34625d90d2a6978272-image.png)

深搜陆地，遇到边界就修改标记，不计入总数，140ms，仅供参考。

```python []
class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        def dfs(i, j):
            grid[i][j] = 1
            for di, dj in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                x, y = i + di, j + dj
                if 0 <= x < m and 0 <= y < n:
                    if not grid[x][y]:
                        dfs(x, y)
                else:
                    nonlocal flag
                    flag = False
        ans = 0
        for i, j in itertools.product(range(m), range(n)):
            flag = True
            if not grid[i][j]:
                dfs(i, j)
                ans += flag
        return ans
```
