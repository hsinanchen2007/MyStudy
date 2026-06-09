搬运题解第二篇的思路，用python实现。
另外感觉这题目理解有点争议。

```
class Solution:
    def balancedStringSplit(self, s: str) -> int:
        i = 0
        count = 0
        r = 0
        while (i < len(s)):
            if s[i] =='R':
                count += 1
            else:
                count -= 1
            if count == 0:
                r += 1
            i+=1
        return r
```

