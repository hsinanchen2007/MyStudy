
```
class Solution:
    def reverseOnlyLetters(self, S: str) -> str:
        if not S:
            return S
        S = list(S)
        start = 0
        end = len(S) - 1
        while end - start >= 1:
            if  (97 <= ord(S[start].lower()) <= 122) and (97 <= ord(S[end].lower()) <= 122):
                S[start], S[end] = S[end], S[start]
                start += 1
                end -= 1
            if (97 <= ord(S[start].lower()) <= 122) == False:
                start += 1
            if (97 <= ord(S[end].lower()) <= 122) == False:
                end -= 1
        
        return ''.join(S)
```
