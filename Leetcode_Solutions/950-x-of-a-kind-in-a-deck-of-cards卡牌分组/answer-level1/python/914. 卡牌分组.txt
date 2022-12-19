### 解题思路
使用最大公因数，collections.Counter可以直接计数
### 代码

```python3
from functools import reduce
import collections
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        if not deck:
            return False
        def gcd(a, b):
            if b == 0:
                return a
            else:
                return gcd(b, a%b)
        return reduce(gcd, collections.Counter(deck).values()) > 1


        
```