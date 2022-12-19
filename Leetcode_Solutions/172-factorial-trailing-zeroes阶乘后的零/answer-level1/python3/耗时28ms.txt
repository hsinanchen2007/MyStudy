```
class Solution:
    def trailingZeroes(self, n: int) -> int:
        num = 0
        while n !=0:
            n1 = n / 5
            num += int(n1)
            if n1 >= 5:
                n = n1
            else:
                n = 0
        return(num)
        
```
