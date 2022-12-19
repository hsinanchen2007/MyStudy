```
class Solution:
    def isUgly(self, num: int) -> bool:
        if num<1:
            return False
        elif num<=5 and num!=4:
            return True
        while num%2==0:
            num/=2
        while num%3==0:
            num/=3
        while num%5==0:
            num/=5
        if num>0 and num<6:
            return True
        else:
            return False
```
