```
class Solution:
    def addDigits(self, num: int) -> int:
        str1 = str(num)
        n1 = len(str1)
        if n1 < 2:
            return(num)
        while n1 > 1:
            num1 = 0
            for i in range(n1):
                num1 += int(str1[i])
            str1 = str(num1)
            n1 = len(str1)
        return(num1)
```
