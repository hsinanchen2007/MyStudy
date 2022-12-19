### 解题思路
此处撰写解题思路

### 代码

```python
import copy

class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0 or x % 10 == 0 and x > 10:
            return False
        result, i = 0, copy.copy(x)
        while i != 0:
            result = result * 10 + i % 10
            i //= 10
        return True if result == x else False

```