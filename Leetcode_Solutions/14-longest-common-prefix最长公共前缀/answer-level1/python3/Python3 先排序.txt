```
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ''

        strs = sorted(strs, key=len)
        first_s = strs[0]
        for i in range(len(strs[0])):
            for s in strs[1:]:
                if s[i] != first_s[i]:
                    return first_s[:i]
        return first_s  
```
