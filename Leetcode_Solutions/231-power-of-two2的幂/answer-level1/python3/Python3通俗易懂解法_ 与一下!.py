### 解题思路
举个例子:
8 = (1000)
7 = (0111)
8 & 7 = (0000)

n & (n-1) == 0 条件是恒成立的

### 代码

```python3
import math

class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        return n > 0 and n & (n - 1) == 0
```