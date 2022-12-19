```
class Solution:
    def reverseOnlyLetters(self, S: str) -> str:
        s1 = [i for i in S]
        start = 0
        end = len(s1)-1
        while start<= end:
            if s1[start].isalpha() and s1[end].isalpha():
                s1[start],s1[end] = s1[end],s1[start]
                start += 1
                end -= 1
            elif not s1[start].isalpha():
                start += 1
            elif not s1[end].isalpha():
                end -= 1
        s1 = ''.join(s1)
        return s1
        
```
