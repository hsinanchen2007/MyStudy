
```python []
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ss=[]
        maxl=0
        for i in list(s):
            if i not in ss:
                ss.append(i)
            else:
                ss=ss[ss.index(i)+1:]
                ss.append(i)
            maxl=max(maxl,len(ss))
        return maxl
```
