### 解题思路
转换成对数，标准的计算器开方方法

### 代码

```python3
from math import e, log
class Solution:
    def mySqrt(self, x: int) -> int:
        if x==0:return 0
        n = int(e**(0.5 * log(x)))
        return n if (n+1)**2 > x else n+1
```