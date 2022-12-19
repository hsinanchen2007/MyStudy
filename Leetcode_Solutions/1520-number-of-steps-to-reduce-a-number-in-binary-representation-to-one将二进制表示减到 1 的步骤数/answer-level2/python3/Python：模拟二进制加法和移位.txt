```
class Solution:
    def numSteps(self, s: str) -> int:
        if s == "1":return 0
        step = 0
        while s != "1":
            if s[-1] == '0':
                s = s[:-1]
            else:
                n = len(s)
                right = n - 1
                while right >= 0 and s[right] == '1':right -= 1
                if right < 0:s = '1' +'0'*n
                else:
                    s = s[:right]+'1'+'0'*(n - right - 1)
            step += 1
        return step
```
