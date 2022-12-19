```
class Solution:
    def reverse(self, x: int) -> int:
        sign = 1 if x>0 else -1 if x<0 else 0
        a = int(str(abs(x))[::-1]) #[::-1]代表字符串反转
        return (a < 2**31)*a*sign
```

执行用时间：36 ms
内存消耗：13.5 MB



