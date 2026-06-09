```
class Solution:
    def convertToBase7(self, num: int) -> str:
        s=0
        i=0
        if num<0:
            h='-'
            num=abs(num)
        else:
            h=''
        while num!=0:
            s+=((num%7)*(10**i))
            num//=7
            i+=1
        return h+str(s)
```
