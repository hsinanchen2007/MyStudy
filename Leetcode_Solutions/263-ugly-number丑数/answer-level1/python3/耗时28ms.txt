```
class Solution:
    def isUgly(self, num: int) -> bool:
        if num == 0:
            return(False)
        while num != 1:
            n1 = num % 2
            n2 = num % 3
            n3 = num % 5
            if n1 == 0 or n2 == 0 or n3 == 0:
                if n1 == 0:
                    num = int(num / 2)
                elif n2 == 0:
                    num = int(num / 3)
                elif n3 == 0:
                    num = int(num / 5)
            else:
                return(False)
        return(True)
```
