```
class Solution:
    def compressString(self, S: str) -> str:
        if not S:
            return S
        res=""
        char=S[0]
        start=0
        for i in range(len(S)):
            if not S[i]==char:
                res+=char+str(i-start)
                char=S[i]
                start=i
        res+=char+str(len(S)-start)
        if len(res)<len(S):
            return res
        else:
            return S
```
