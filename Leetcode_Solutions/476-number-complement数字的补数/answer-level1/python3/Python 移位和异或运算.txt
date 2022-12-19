先移位，再作异或运算

```
class Solution(object):
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        temp = 1
        while temp < num:
            temp <<= 1
            temp += 1
        return temp^num
        
```
