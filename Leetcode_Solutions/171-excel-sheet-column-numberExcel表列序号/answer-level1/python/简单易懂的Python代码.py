其实这道题跟168是互逆的
```
class Solution:
    def titleToNumber(self, s: str) -> int:
        d = dict()
        for i in range(ord('A'), ord('Z')+1):
            d[chr(i)] = i - 64
        res = 0
        for i in range(len(s)):
            res = res * 26 + d[s[i]]
        return res
```
