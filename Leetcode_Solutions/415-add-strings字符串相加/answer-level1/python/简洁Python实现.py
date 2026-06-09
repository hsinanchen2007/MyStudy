### 代码

```python3
class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        from itertools import zip_longest
        res = ""
        carry = 0
        for a, b in zip_longest(num1[::-1], num2[::-1], fillvalue = "0"):
            carry, mod = divmod(int(a) + int(b)+ carry, 10)
            res =  str(mod) + res
        if carry > 0:
            res = "1" + res
        return res
```