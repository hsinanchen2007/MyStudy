```python
class Solution:
    def validMountainArray(self, A: List[int]) -> bool:
        if len(A) < 3:
            return False
        index_ = A.index(max(A))
        if index_ == 0 or index_ == len(A) - 1:
            return False
        for i in range(0, index_):
            if A[i] >= A[i + 1]:
                return False
        for i in range(index_, len(A) - 1):
            if A[i] <= A[i + 1]:
                return False
        return True
```
