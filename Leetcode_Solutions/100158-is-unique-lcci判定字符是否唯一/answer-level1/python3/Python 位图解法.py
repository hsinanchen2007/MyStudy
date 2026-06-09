```
class Solution:
    def isUnique(self, astr: str) -> bool:
        bit=0
        for ch in astr:
            mask=ord(ch)-ord('a')
            if bit & (1<<mask) !=0:
                return False
            else:
                bit = bit | (1<<mask)
        return True

```
