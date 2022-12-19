```
class Solution:
    def reverseOnlyLetters(self, S: str) -> str:
        s=list(S)
        start,end=0,len(s)-1

        while start<end:
            if s[start].isalpha() and s[end].isalpha():
                s[start],s[end]=s[end],s[start]
                start+=1
                end-=1
            elif not s[start].isalpha():
                start+=1
            elif not s[end].isalpha():
                end-=1
        return "".join(s)
```
