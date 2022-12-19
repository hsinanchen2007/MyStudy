```
class Solution:
    def compressString(self, S: str) -> str:
        first, res = 0, ''
        S += '#'
        for i in range(len(S)):
            if S[i] != S[first]:
                res += f'{S[first]}{i-first}'
                first = i
        return res if len(res)<len(S)-1 else S[:-1]
```
