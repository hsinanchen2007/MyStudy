### 解题思路
使用Python自带的Counter进行计数。

### 代码

```python3
from collections import Counter

def gcd(x, y):
    return x if y == 0 else gcd(y, x % y)

class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        cnt = Counter(deck)
        g = 0
        for num in cnt:
            g = gcd(g, cnt[num])
        return g >= 2
        
```