python3
```
class Solution:
    def repeatedStringMatch(self, A: str, B: str) -> int:
        if set(B).issubset(set(A)) :
            a=max(1,len(B)//len(A))
            b=max(3,(len(B)*2-1)//len(A)+2)
            for i in range(a,b):
                if B in A*i:break
                else:i=-1
            return i
        else:return -1
```
