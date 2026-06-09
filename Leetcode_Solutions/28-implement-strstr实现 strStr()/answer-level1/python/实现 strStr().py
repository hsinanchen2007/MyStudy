![image.png](https://pic.leetcode-cn.com/010cf51c88ef1b9183ac0675d9c1b0340a0a4ce614150d4c76882cb83df6d651-image.png)


```
class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if len(needle) > len(haystack): return -1
        if len(needle) == 0: return 0
        if set(needle).difference(set(haystack)): return -1

#         for idx in range(len(haystack)): (普通暴力法))
#             if haystack[idx:idx + len(needle)] == needle:
#                 return idx
#         return -1
        
        idx = 0
        while idx < len(haystack):
            
            if haystack[idx:idx+len(needle)] == needle:
                return idx
            elif (idx + len(needle) < len(haystack)) and (haystack[idx+len(needle)] in needle):
                idx += 1
            else:
                idx += len(needle)
                
        return -1
```