利用字符串倒置加判断即可
```
class Solution:
    def reverse(self, x: int) -> int:
        s = str(x)
        if x < 0:
            ss = s[:-len(s):-1]
        else:
            ss = s[::-1]
        sss = int(ss)
        if x < 0:
            sss = sss * -1
        if -2**31 <= sss <= 2**31 -1: 
            return sss
        else:
            return 0

```
