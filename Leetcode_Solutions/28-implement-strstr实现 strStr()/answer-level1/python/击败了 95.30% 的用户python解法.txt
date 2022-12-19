
```
class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if len(haystack)==0 and len(needle)==0:
            return 0
        if haystack == needle:
            return 0
        else:
            n = len(needle)
            i = 0
            a = False
            while i+n <=len(haystack):
                if haystack[i:i+n]==needle:
                    a = True
                    break
                i+=1
            if a ==True:
                return i
            else:
                return -1
```
