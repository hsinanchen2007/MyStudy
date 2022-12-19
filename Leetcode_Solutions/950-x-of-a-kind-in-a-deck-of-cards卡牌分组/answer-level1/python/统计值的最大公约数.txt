### 解题思路
统计值的最大公约数

### 代码

```python3
import math
import numpy as np 
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        # 多个数的最大公约数
        rust = dict(zip(deck, deck))
        for k, v in rust.items():
            rust[k] = deck.count(k)
        rust1 = dict(zip(rust.values(), rust.keys()))
        it = list(rust1.keys())
        size = len(it)
        if size == 1 and it[0]>=2:
            return True
        elif size ==1 and it[0]==1:
            return False
        elif size >= 2:
            max_gcd = math.gcd(it[0], it[1])
            try:
                for i in range(2, size):
                    max_gcd = math.gcd(max_gcd, it[i])
            except:
                pass
        if max_gcd>=2:
            return True
        else:
            return False
```