### 解题思路


### 代码

```python
class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        a=set(["1","2","3","4","5","6","7","8","9","0"])
        str=list(str)
        sign=1
        b=0
        c=0
        d=0
        for i in range(len(str)):
            if str[i]!=" " :
                if str[i]=="-" and b==0 and d==0:
                    str[i]="0"
                    sign=-1
                    b=1
                if str[i]=="+" and b==0 and d==0:
                    str[i]="0"
                    b=1
                if str[i]  in a:
                    c=c*10+int(str[i])
                    d=1
                else:
                    break
            if str[i]==" " and(b!=0 or d!=0):
                break


        c=sign*c
        if c>2147483647 :
            return 2147483647 
        elif c<-2147483648 :
            return -2147483648 
        else:
            return c
```