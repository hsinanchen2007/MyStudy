### 解题思路
看大佬的，简单的数学推导

### 代码

```python
from math import sqrt 
class Solution(object):
    def bulbSwitch(self, n):
        """
        :type n: int
        :rtype: int
        """
        # return int(pow(n, 0.5)) # 20%
        return int(sqrt(n))  # 超越70%
```