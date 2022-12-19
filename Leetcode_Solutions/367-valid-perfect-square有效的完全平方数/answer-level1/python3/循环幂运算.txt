借鉴求2次幂、3次幂、4次幂时用的累乘法思想。
```
class Solution(object):
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        temp, i = 0, 0
        while temp <= num:
            temp = i**2
            if temp == num:
                return True
            i += 1
        return False
```
