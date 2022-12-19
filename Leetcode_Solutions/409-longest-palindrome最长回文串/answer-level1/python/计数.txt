

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:

        dct = {}
        ans = 0
        for ch in s:
            if ch not in dct:
                dct[ch] = 1
            else:
                dct[ch] += 1
            if dct[ch]==2:
                dct[ch] = 0
                ans += 2
        return ans if ans==len(s) else ans+1
```