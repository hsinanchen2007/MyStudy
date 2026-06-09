迭代器
```python []
from itertools import cycle, count
class Solution:
    def distributeCandies(self, c: int, n: int) -> List[int]:
        a = [0] * n
        for i, j in zip(cycle(range(n)), count(1)):
            if j >= c:
                a[i] += c
                return a
            a[i] += j
            c -= j
```