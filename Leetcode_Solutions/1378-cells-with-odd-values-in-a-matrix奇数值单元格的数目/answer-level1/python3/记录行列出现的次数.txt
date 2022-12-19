### 代码

```python3
class Solution:
    def oddCells(self, n: int, m: int, indices: List[List[int]]) -> int:
        colums = [False]*m
        rows = [False]*n
        for ind in indices:
            r = ind[0]
            c = ind[1]
            rows[r] = not rows[r]
            colums[c] = not colums[c]
        c = colums.count(True)
        r = rows.count(True)
        return r*m + c*n - r*c*2
```