### 解题思路


### 代码

```python
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        x_ori = x
        if x < 0 or (x != 0 and x % 10 == 0):
            return False
        else:
            result = 0
            while result < x:
                result = result * 10 + x % 10
                x = x / 10
            if result == x or result / 10 == x:
                return True
            else:
                return False
```