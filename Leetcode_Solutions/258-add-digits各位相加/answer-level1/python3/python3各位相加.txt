把十进制转化为九进制，同时考虑两类特殊值。
```
class Solution:
    def addDigits(self, num: int) -> int:
        if num==0:
            return 0
        if num%9==0:
            return 9
        else:
            return num%9
```
