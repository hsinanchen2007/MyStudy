### 代码

```python3
class Solution:
    def combine(self, n, k):
        from itertools import combinations
        b = list(range(1, n+1))
        a = list(combinations(b, k))
        return list(map(list, a))
```