转成求复数差值的辐角一致性问题。

```python
from cmath import phase as p
class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        c, a = complex, coordinates
        d = {p(c(*a[1]) - c(*a[0])), p(c(*a[0]) - c(*a[1]))}
        return all(p(c(*x) - c(*a[0])) in d for x in a[2: ])
```
