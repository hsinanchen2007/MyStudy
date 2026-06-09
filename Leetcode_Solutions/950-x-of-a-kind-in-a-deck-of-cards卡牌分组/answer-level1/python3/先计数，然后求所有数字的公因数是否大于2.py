### 解题思路
此处撰写解题思路

### 代码

```python3
from collections import Counter
from fractions import gcd
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        if deck == []: return False
        times = Counter(deck)
        return reduce(gcd, times.values()) >= 2

```