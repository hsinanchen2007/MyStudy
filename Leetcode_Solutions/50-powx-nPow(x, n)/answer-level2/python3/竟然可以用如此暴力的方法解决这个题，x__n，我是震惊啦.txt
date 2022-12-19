### 解题思路
此处撰写解题思路

### 代码

```python3
from functools import lru_cache

class Solution:
    @lru_cache(maxsize=None)
    def myPow(self, x: float, n: int) -> float:
        # if n < 0 : return self.myPow(1 / x, -n)
        # if n == 0: return 1
        # if n % 2 == 0:
        #     return self.myPow(x*x, n//2)
        # else:
        #     return x * self.myPow(x*x, n//2)



        return x**n




```