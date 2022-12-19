```
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if len(needle) == 0:
            return 0
        if len(haystack) == 0:
            return -1
        
        for i in range(len(haystack)):
            nP = 0
            if haystack[i] == needle[nP]:
                while True:
                    nP = nP+1
                    if i+nP >= len(haystack) and nP < len(needle):
                        return -1
                    if nP >= len(needle):
                        return i
                    if haystack[i+nP] != needle[nP]:
                        break                 
        return -1
