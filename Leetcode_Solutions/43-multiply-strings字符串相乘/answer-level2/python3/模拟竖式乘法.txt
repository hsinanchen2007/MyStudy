```
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        c = 0
        a=ord('0')
        res = ['0' for i in range(len(num1)+len(num2))]
        for i in range(len(num1)-1, -1, -1):
            for j in range(len(num2)-1, -1, -1):
                n = (ord(num1[i]) - ord('0'))* (ord(num2[j]) - ord('0') ) + ord(res[1+i+j]) - ord('0') + c
                c = n//10
                n = n % 10
                res[i+j+1] = chr(ord('0') + n)
            if c > 0:
                res[i] =  chr(ord(res[i]) + c)
                c = 0
        if c > 0:
            res[0] =  chr(ord(res[0]) + c)
            c = 0
        r = ''.join(res).lstrip('0')
        if r == '':
            r = '0'
        return r
 
```
