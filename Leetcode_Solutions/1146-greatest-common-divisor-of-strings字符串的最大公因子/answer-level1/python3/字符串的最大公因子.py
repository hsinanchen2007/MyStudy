```
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if not str1 and not str2:
            return ""
        length = min(len(str1), len(str2))
        Flag = 0

        for i in range(length):
            if length % (i + 1) == 0 and (str1[:i+1] * (len(str1) // (i + 1)) == str1) and (str1[:i+1] * \
                (len(str2) // (i + 1)) == str2):
                Flag = i + 1
        return str1[:Flag] 
```
