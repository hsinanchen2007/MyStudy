解法已经有很多人解释清楚了，这里给一个通俗的写法。

```Python3
from itertools import accumulate

class Solution:
    def trap(self, height: List[int]) -> int:
        a = list(accumulate(height, max))
        b = list(accumulate(height[::-1], max))[::-1]
        res = 0
        for x, y, z in zip(a, b, height):
            res += min(x, y) - z
        return res

```
