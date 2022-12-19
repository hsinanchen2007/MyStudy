数据小到不用其他多余剪枝，越界也没必要判断。

```python []
class Solution:
    def queensAttacktheKing(self, queens: List[List[int]], king: List[int]) -> List[List[int]]:
        p = {(x, y) for x, y in queens}
        d = {(1, 0), (0, 1), (0, -1), (-1, 0), (1, 1), (1, -1), (-1, 1), (-1, -1)}
        kx, ky = king
        ans = []
        for t in range(1, 8):
            c = set()
            for i, j in d:
                q = (kx + t * i, ky + t * j)
                if q in p:
                    ans += [q]
                    c |= {(i, j)}
            d -= c
        return ans
```
