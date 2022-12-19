### 解题思路

深搜

### 代码

```python []
class Solution:
    def pondSizes(self, land: List[List[int]]) -> List[int]:
        m, n = len(land), len(land[0])
        d = ((-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1))
        ans = []
        def f(i, j):
            nonlocal count
            count += 1
            for di, dj in d:
                x, y = i + di, j + dj
                if 0 <= x < m and 0 <= y < n and not land[x][y]:
                    land[x][y] = 1
                    f(x, y)
        for i, j in itertools.product(range(m), range(n)):
            if not land[i][j]:
                land[i][j], count = 1, 0
                f(i, j)
                ans.append(count)
        return sorted(ans)
```