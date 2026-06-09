
```python []
class Solution:
    def multiply(self, A: int, B: int) -> int:
        if A > B:
            A, B = B, A
        return B + (A != 1 and self.multiply(A - 1, B))
```