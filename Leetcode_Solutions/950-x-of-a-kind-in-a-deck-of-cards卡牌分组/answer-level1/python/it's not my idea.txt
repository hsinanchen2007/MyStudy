### 解题思路
此处撰写解题思路

### 代码

```python3
from math import gcd
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        values = collections.Counter(deck).values()
        return reduce(gcd, values) > 1
```