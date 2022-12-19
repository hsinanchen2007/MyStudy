```
class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        d = {}
        res = 0
        left = 0
        right = len(s)
        for i in range(len(s)):
            if s[i] not in d.keys():
                d[s[i]] = 1
            else:
                d[s[i]] += 1
            if len(d.keys()) == 3:
                right = i
                break
        while right < len(s):
            res += len(s) - right
            if d[s[left]] <= 1:
                right += 1
                while right < len(s) and s[left] != s[right]:
                    d[s[right]] += 1
                    right += 1
                    
            else:
                d[s[left]] -= 1
            left += 1
        return res
```
