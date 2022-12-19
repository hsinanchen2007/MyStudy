```
class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        res=[]
        up=0
        max_=max(len(num1),len(num2))
        for i in range(max_-len(num1)):
            num1='0'+num1
        for i in range(max_-len(num2)):
            num2='0'+num2
        i=max_-1
        while i>=0:
            print (i)
            tmp=ord(num1[i])+ord(num2[i])+up-2*ord('0')
            if tmp>=10:
                tmp=tmp-10
                up=1
            else:
                up=0
            res.append(chr(tmp+ord('0')))
            i=i-1
        if up:
            res.append('1')
        return ''.join(res[::-1])


```
