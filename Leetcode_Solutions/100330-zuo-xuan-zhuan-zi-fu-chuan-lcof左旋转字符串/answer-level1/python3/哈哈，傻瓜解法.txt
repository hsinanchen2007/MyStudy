```
class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        s1=''
        m=len(s)
        for i in range(n):
            s1+=s[i]
        return s[n:]+s1
```
