```python
class Solution:
    def freqAlphabets(self, s: str) -> str:
        i = len(s) - 1
        ans = ''
        while i >= 0:
            if s[i] == '#':
                ans = chr(int(s[i - 2:i]) - 1 + ord('a')) + ans
                i -= 3
            else:
                ans = chr(int(s[i]) - 1 + ord('a')) + ans
                i -= 1
        return ans
```