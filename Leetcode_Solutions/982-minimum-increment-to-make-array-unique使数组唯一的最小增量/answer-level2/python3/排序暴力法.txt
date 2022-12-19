```
class Solution:
    def minIncrementForUnique(self, A):
        A.sort()
        count = 0
        for i in range(1, len(A)):
            while A[i] <= A[i-1]:
                count += A[i-1] - A[i] + 1
                A[i] += A[i-1] - A[i] + 1
        return count
```
