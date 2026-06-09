
```python []
class Solution:
    def printNumbers(self, n: int) -> List[int]:
        return range(1, 10 ** n)
```
```python []
class Solution:
    def printNumbers(self, n: int) -> List[int]:
        return [*range(1, 10 ** n)]
```