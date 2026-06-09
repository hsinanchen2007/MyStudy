 L = [['I','V'], ['X','L'], ['C', 'D'], ['M']]
原因是每个不同数位上都有两个字符（如个位有I，V，十位X，L，最高位例外）。
好处是方便做循环，且容易扩展到更高位，只需要在索引中加上就OK。

```
class Solution:
    def intToRoman(self, num: int) -> str:
        L = [['I','V'], ['X','L'], ['C', 'D'], ['M']]
        ans = ""
        i = 0
        while num > 0:
            n = num%10
            if n == 0:
                pass
            elif n < 4:
                ans = L[i][0]*n + ans
            elif n == 4:
                ans = L[i][0] + L[i][1] + ans
            elif n < 9:
                ans = L[i][1] + L[i][0]*(n-5) + ans
            else:
                ans = L[i][0] + L[i+1][0] + ans
            num = int(num/10)
            i += 1
        return ans 
```
