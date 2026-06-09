```
class Solution:
    def shiftingLetters(self, S: str, shifts: List[int]) -> str:
        pre = 0
        k = 0
        Slist = list(S)
        for i in range(len(shifts)-1, -1, -1):
            shifts[i] = (shifts[i] + pre) % 26
            pre = shifts[i]
            k = ord(Slist[i]) + shifts[i] if ord(Slist[i]) + shifts[i]<= 122 else ord(Slist[i]) + shifts[i] - 26 
            Slist[i] = chr(k)
        return ''.join(Slist)
```
