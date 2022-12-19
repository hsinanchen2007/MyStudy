```
class Solution:
    def isHappy(self, n: int) -> bool:
        list1 = []
        str1 = str(n)
        num1 = 0
        while True:
            for i in str1:
                num1 += int(i)**2
            if num1 == 1:
                return(True)
            if num1 not in list1:
                list1.append(num1)
            else:
                return(False)
            str1 = str(num1)
            num1 = 0
```
