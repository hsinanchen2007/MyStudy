
```
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        if not s:return 0
        start,res = 0,0
        lookup = set()
        for i in s:
            while i in lookup:
                lookup.remove(s[start])
                start +=1
            lookup.add(i)
            res=max(len(lookup),res)
        return res
```
