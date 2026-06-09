```
class Solution:
    def isUgly(self, num: int) -> bool:
        if num<=0:
            return False
        if num==1:
            return True
        
        while True:
            if num%2!=0 and num%3!=0 and num%5!=0:
                if num==1:
                    return True
                else:
                    return False
            if num%2==0:
                num=num/2
            if num%3==0:
                num=num/3
            if num%5==0:
                num=num/5
```