```
class Solution:
    def longestPrefix(self, s: str) -> str:
        result = ''
        length = len(s)
        for i in range(1,length):
            index = length-i
            if s[:index] == s[-index:]:
                result = s[:index]
                break
        return result
```
