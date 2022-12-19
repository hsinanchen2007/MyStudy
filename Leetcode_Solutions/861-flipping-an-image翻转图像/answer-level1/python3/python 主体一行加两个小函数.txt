```
class Solution:
    def flipAndInvertImage(self, A: List[List[int]]) -> List[List[int]]:
        return [map(self.reversePhase, row) for row in list(map(self.reverseHorizontal, A))]
    def reversePhase(self, x):
        return 1 - x

    def reverseHorizontal(self, x):
        return x[::-1]
```
