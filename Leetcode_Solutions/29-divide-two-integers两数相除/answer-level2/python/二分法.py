### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def divide(self,a,b):
        state=0
        if a*b<0:state=1
        a=abs(a) ;b=abs(b)
        i=0 ;j=a
        while i<j:
            m=int((i+j)/2)
            if m*b-a>-b and m*b<=a:
                i=m
                break
            elif m*b-a>0:
                j=m-1
            elif m*b-a<=-b:
                i=m+1
        if state==1:
            i=max(-2**31,-i)
        else:
            i=min(i,2**31-1)
        return i
```