应该算是最正常解法，就是不知道为啥这么慢

```
class Solution:
    def validMountainArray(self, A: List[int]) -> bool:
        n = len(A)
        k = 1
        while k < n and A[k] > A[k - 1]:
            k += 1
        if k == 1 or k==n:
            return False
        while k < n and A[k] < A[k - 1]:
            k += 1
        return k == n
```
