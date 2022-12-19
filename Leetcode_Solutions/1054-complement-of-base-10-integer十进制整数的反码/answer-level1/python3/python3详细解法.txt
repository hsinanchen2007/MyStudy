```
class Solution:
    def bitwiseComplement(self, N: int) -> int:
        s=bin(N)[2:]
        for i in range(len(s)):
            if int(s[i])==0:
                s=s[:i]+'1'+s[i+1:]
            else:
                s=s[:i]+'0'+s[i+1:]
        return int(s,2)
```
