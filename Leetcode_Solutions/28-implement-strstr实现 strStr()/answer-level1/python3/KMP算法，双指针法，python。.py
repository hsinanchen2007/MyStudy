```
class Solution:
    def computeArray(self,pattern):
        lps = [0]*len(pattern)
        index = 0
        i = 1
        while i < len(pattern):
            if pattern[i] == pattern [index]:
                lps[i] = index+1
                index += 1
                i += 1
            else:
                if index != 0:
                    index = lps[index-1]
                else:
                    lps[i] = 0
                    i += 1
        return lps
    def KMP(self,text,pattern):
        lps = self.computeArray(pattern)
        i = 0
        j = 0
        while i <len(text) and j < len(pattern):
            if text[i] == pattern[j]:
                i += 1
                j += 1
            else:
                if j != 0:
                    j = lps[j-1]
                else:
                    i += 1
        return i-len(pattern) if j == len(pattern) else -1
   
     def strStr(self, haystack: str, needle: str) -> int:
        if not needle:
            return 0
        return self.KMP(haystack,needle)
```

双指针-python
```
class Solution:
    #use two needles
    def strStr(self, haystack: str, needle: str) -> int:
        if not needle:
            return 0
        m = len(needle)
        i = 0
       
        while i < len(haystack)-m +1: #the rest of (needle.size-1) strs do not need to compare
            j = 0
            while j < m:
                if haystack[i+j] != needle[j]:
                    break
                else:
                    j += 1
            
            if j == m:
                 return i
            i += 1
        return -1
```
