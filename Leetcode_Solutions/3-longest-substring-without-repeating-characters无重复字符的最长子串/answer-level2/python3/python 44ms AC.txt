python 44ms AC
```python
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        s1 = ''
        lens = 0
        for char in list(s):
            s1 = s1.split(char)[-1] + char
            lens = len(s1) if len(s1) > lens else lens
        return lens
```
