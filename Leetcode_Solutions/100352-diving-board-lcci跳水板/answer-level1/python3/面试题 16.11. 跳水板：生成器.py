
```python []
class Solution:
    def divingBoard(self, shorter: int, longer: int, k: int) -> List[int]:
        if k and longer - shorter:
            yield from range(shorter * k, longer * k + 1, longer - shorter)
        elif k:
            yield longer * k
```