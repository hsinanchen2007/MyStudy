### 解题思路
> 直观上看，先对每个字母出现次数统计， 需要找出所有出现次数的gcd，然后判定gcd大于等于2的符合要求

### 代码

```python3
from math import gcd
from functools import reduce


class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        if not deck:
            return False
        counter = collections.Counter(deck)
        values = counter.values()
        g = reduce(gcd, values)
        return g >= 2
```