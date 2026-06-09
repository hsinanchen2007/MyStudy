```
class Solution:
    def bitwiseComplement(self, N: int) -> int:
        s = bin(N)[2:]
        a = '1'*len(s)
        b = ''
        for i in range(len(a)):
            b += str((int(a[i]) - int(s[i])))
        return int(b,2)
```
