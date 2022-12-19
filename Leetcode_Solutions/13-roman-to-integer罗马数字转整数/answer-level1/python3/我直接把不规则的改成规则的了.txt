
### 代码

```python3
class Solution:
    def romanToInt(self, s):
        S = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000, 'v': 4, 'x': 9, 'l': 40, 'c': 90, 'd': 400, 'm': 900}
        s = s.replace('IV', 'v')
        s = s.replace('IX', 'x')
        s = s.replace('XL', 'l')
        s = s.replace('XC', 'c')
        s = s.replace('CD', 'd')
        s = s.replace('CM', 'm')
        ans = 0
        for i in range(len(s)):
            ans += S[s[i]]
        return ans
```