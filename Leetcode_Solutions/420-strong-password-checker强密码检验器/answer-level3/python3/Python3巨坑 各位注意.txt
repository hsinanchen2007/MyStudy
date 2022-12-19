### 解题思路
Python3巨坑，如果返回int，会自带个小数点2变成2.0，必须更改默认定义，强制返回int才行，坑死了

### 代码

```python3
class Solution:
    def strongPasswordChecker(self,s:str):
        hasN=False
        hasU=False
        hasL=False
        tp={}
        nm=0
        i=0
        while (i<len(s)):
            c=s[i]
            if c.isdigit():
                hasN=True
            if c.isupper():
                hasU=True
            if c.islower():
                hasL=True
            x=i
            while (x<len(s) and s[x]==c):
                x+=1
            l=x-i
            if l>=3:
                nm+=l//3
                tp[l%3]=tp.get(l%3,0)+1
            i=x
        nloss=3-int(hasN)-int(hasU)-int(hasL)
        if (len(s)<6):
            return str(int(max(nloss,6-len(s))))
        if (len(s)<=20):
            return str(int(max(nloss,nm)))
        nd=len(s)-20
        if (nd<tp.get(0,0)):
            return str(int(max(nm-nd,nloss)+len(s)-20))
        nd-=tp.get(0,0)
        nm-=tp.get(0,0)
        if (nd<tp.get(1,0)*2):
            return str(int(max(nm-nd//2,nloss)+len(s)-20))
        nd-=tp.get(1,0)*2
        nm-=tp.get(1,0)
        return str(int(max(nm-nd//3,nloss)+len(s)-20))
```