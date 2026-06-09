调库吧，想不到什么别的思路了
```
class Solution:
    def anagramMappings(self, A: List[int], B: List[int]) -> List[int]:
        return [B.index(i) for i in A]
```
