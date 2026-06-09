
### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        b=[]
        change=1
        if x<0:
            change=-1
        x=str(abs(x))
        x=[i for i in x]
        for i in range(len(x)-1,-1,-1):
            b.append(x[i])
        if b[0]==0:
            b.pop(0)
        if b==[]:
            return 0
        else:
            b = int("".join(b)) * change
            if b<-2**31 or b>2**31-1:
                return 0
            else:
                return b
        

```