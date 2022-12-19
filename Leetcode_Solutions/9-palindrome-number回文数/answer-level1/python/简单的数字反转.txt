### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False 
        z = x
        y = 0
        while x > 0:
            y = y * 10 + x % 10
            x = x / 10
        return z == y
```
很简单的数字反转