```
class Solution:
    def tribonacci(self, n: int) -> int:
        nacci = [0,1,1]
        while len(nacci) <= n:
            nacci.append(nacci[len(nacci)-1]+nacci[len(nacci)-2]+nacci[len(nacci)-3])
        return nacci[n]
```