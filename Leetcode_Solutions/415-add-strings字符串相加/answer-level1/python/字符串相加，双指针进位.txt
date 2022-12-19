```python []
class Solution(object):
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        
        len_1 = len(num1) - 1
        len_2 = len(num2) - 1
        carry = 0
        
        res = []
        while len_1 >= 0 or len_2 >= 0 or carry:
            val_1 = num1[len_1] if len_1 >= 0 else 0
            val_2 = num2[len_2] if len_2 >= 0 else 0
            
            s = int(val_1) + int(val_2) + carry
            
            carry = s // 10
            val = s % 10

            res.append(str(val))

            len_1 -= 1
            len_2 -= 1
        return "".join(reversed(res))            
```
