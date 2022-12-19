```
class Solution:
    def toGoatLatin(self, S: str) -> str:
        yunyin = ["a","A","E","e","I","i","O","o","U","u"]
        S = S.split()
        for i in range(0,len(S)):
            if S[i][0] in yunyin:
                S[i] = S[i]+"ma"+"a"*(i+1)
            else:
                S[i] = S[i][1:]+S[i][:1]+"ma"+"a"*(i+1)
        return " ".join(S) 
```
