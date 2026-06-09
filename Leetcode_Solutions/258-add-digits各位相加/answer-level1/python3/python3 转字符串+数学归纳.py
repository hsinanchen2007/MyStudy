1. 将数字转成字符串，在求和
```
class Solution:
    def addDigits(self, num: int) -> int:
        num=str(num)
        while(len(num)>1):
            tmp=0
            for a in num:
                tmp+=int(a)
            tmp=str(tmp)
            num=tmp
        return int(num)
```
2.数学归纳
```
class Solution:
    def addDigits(self, num: int) -> int:
        if num > 9:
            num = num % 9
            if num == 0:
                return 9
        return num
```
