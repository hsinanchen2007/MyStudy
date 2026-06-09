```
python3
class Solution:
    def compressString(self, S: str) -> str:
        if not S:
            return S

        count = 0
        index = 0
        ret = ""
        for i in range(1, len(S)):
            if S[i] == S[i - 1]:
                continue
            else:
                count = i - index
                ret =  ret + S[index] + str(count)
                index = i

        ret = ret + S[index] + str(len(S) - index)
        
        if len(ret) >= len(S):
            return S
        return ret
```

