```
class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        if num <= 0:
            return(False)
        import math
        vv = math.log(num,4)
        str1 = str(vv)
        list1 = str1.split(".")
        if list1[1] == "0":
            return(True)
        else:
            return(False)
```
