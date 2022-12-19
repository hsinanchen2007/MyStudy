
```
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        i = -1
        a=[]
        s = s.strip()
        while (i>=-len(s)):
            if s[i] == " ":
                break
            else: 
                a.insert(i,s[i])
                i-=1
        return len(a)

```
