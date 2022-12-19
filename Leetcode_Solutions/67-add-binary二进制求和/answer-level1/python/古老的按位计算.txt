### 解题思路
此处撰写解题思路
### 代码

```python
class Solution(object):
    def addBinary(self, a, b):
        if len(a)>len(b):a,b=b,a
        s='' ;l=-len(a)
        sta=0
        for i in range(-1,l-1,-1):
            m=int(a[i]) ;n=int(b[i])
            if sta==0:
                if m+n==2:
                    s='0'+s ;sta=1
                else:
                    s='%d'%(m+n)+s
            else:
                if m+n+1>=2:
                    s='%d'%((m+n+1)%2)+s
                else:
                    s='1'+s
                    sta=0
        if -i<len(b):
            for i in range(i-1,-len(b)-1,-1):
                m=int(b[i])
                if sta==1:
                    if m==1:
                        s='0'+s
                    else:
                        s='1'+s
                        sta=0
                else:s=b[i]+s
            if sta==1:s='1'+s
        elif sta==1:s='1'+s
        return s
        
```