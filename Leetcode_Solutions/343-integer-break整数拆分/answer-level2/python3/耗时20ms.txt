```
class Solution:
    def integerBreak(self, n: int) -> int:
        if n == 2:
            return(1)
        elif n == 3:
            return(2)
        else:
            n1 = int(n / 2)
            n2 = n % 2
            if n2 == 0:
                oushu = 2 ** n1
            else:
                oushu = 2 ** (n1-1) * 3
            num1 = int(n / 3)
            num2 = n % 3
            if num2 == 0:
                jishu = 3 ** num1
            elif num2 == 1:
                jishu = 3 ** (num1-1) * 4
            elif num2 == 2:
                jishu = 3 ** num1 * 2
            return(max(jishu,oushu))
```
