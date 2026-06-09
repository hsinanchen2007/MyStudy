```
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        b = list(map(str, digits))
        c = int(''.join(b))
        c += 1
        return list(map(int, str(c)))
```
