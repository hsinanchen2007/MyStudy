```
class Solution:
    def isMonotonic(self, A: List[int]) -> bool:
        A_sort1=sorted(A)
        A_sort2=sorted(A,reverse=True)
        if A_sort1==A or A_sort2==A:
            return True
        return False
```
