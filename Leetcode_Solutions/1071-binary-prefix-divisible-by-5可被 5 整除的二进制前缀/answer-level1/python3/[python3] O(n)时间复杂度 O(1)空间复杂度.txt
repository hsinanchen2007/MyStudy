```python
class Solution:
    def prefixesDivBy5(self, A: List[int]) -> List[bool]:
        size = len(A)
        for i in range(1, size):
            A[i] += 2 * A[i-1]
            A[i-1] = not A[i-1] % 5
        A[i] = not A[i] % 5
        return A
```
