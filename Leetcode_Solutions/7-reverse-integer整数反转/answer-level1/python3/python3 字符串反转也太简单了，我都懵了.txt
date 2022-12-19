

```
class Solution:
    def reverse(self, x: int) -> int:
        s = str(x)
        flag=1
        if s[0]=='-':
            s=s[1:]
            flag=-1
        s = s[::-1]
        y = flag*int(s)
        if y >= -2**31 and y <= 2**31-1: return y
        else: return 0
```
