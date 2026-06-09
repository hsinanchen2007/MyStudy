```
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        if s=="":
            return 0
        s=s.strip()
        s_list=s.split(" ")
        return s_list[-1].__len__()
```
