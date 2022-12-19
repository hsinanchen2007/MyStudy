```
class Solution:
    def isMonotonic(self, A: List[int]) -> bool:
        A_sort=sorted(A)
        return A==A_sort or A==A_sort[::-1]
```
