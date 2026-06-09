```python3
class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
      return sorted(list(map(lambda num:num*num,A)))
```