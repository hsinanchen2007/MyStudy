查找top k问题，只需要O(n)的时间，没多想，直接水过

```
class Solution(object):
    def randomized_select(self,A, p, r, i):
        if p == r:
            return A[p]
        q = self.randomized_partition(A, p, r)
        k = q - p + 1
        if i == k:
            return A[q]
        elif i < k:
            return self.randomized_select(A, p, q - 1, i)
        else:
            return self.randomized_select(A, q + 1, r, i - k)


    import random

    def randomized_partition(self,A, p, r):
        i = random.randint(p, r)
        t = A[r]
        A[r] = A[i]
        A[i] = t
        x = A[r]
        i = p - 1
        for j in range(p, r):
            if A[j] < x:
                i += 1
                t = A[i]
                A[i] = A[j]
                A[j] = t
        A[r] = A[i + 1]
        A[i + 1] = x
        return i + 1
    def kthSmallest(self, matrix, k):
        import numpy as np
        arr = np.asarray(matrix).reshape(-1)
        r = self.randomized_select(arr, 0, len(arr) - 1, k)
        return r
```


