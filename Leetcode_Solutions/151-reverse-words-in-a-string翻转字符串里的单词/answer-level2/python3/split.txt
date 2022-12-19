```
class Solution:
    def reverseWords(self, s: str) -> str:
        sp = s.split()
        sp.reverse()
        return ' '.join(sp)
```
