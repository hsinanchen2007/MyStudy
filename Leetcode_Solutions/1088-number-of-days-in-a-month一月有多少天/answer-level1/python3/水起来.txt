```
class Solution:
    def numberOfDays(self, Y: int, M: int) -> int:
        third_one=[1,3,5,7,8,10,12]
        third_zero=[4,6,9,11]
        if M in third_one:
            return 31
        elif M in third_zero:
            return 30
        else:
            if Y%100==0:
                if Y%400==0:
                    return 29
                else:
                    return 28
            else:
                if Y%4==0:
                    return 29
                else:
                    return 28
```
