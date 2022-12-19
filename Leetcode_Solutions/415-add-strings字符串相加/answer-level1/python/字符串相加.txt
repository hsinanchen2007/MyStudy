- 注意字符串不能直接更改赋值 a = 'abs'  a[0]='s'是不被允许的
```
class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        carr = 0
        res = ""
        if len(num1)<len(num2):
            num1,num2=num2,num1
        for i in range(len(num1)):
            if i < len(num2):
                temp = carr+ (ord(num1[-1-i])-ord('0')) + (ord(num2[-1-i])-ord('0'))
            else:
                # if carr == 0: break
                temp = carr+ (ord(num1[-1-i])-ord('0'))
            
            if temp >= 10:
                temp-=10
                carr = 1
            else:
                carr = 0
            res = str(temp)+res
            
        if carr >= 1:
            res = '1'+res
        return res
```
