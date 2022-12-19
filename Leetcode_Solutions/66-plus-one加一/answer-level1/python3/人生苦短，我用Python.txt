```
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        digits = int("".join(list(map(str,digits))))
        digits += 1
        return list(str(digits))

```
感觉用Python就像是在作弊一样....