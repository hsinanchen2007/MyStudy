### 解题思路
如果按照正常思路从左端到右端排会比较繁琐, 但是从右端往左端排就很容易了

### 代码

```python3
class Solution:
    def merge(self, A, m, B, n):
        """
        Do not return anything, modify A in-place instead.
        """
        idx1 = m - 1
        idx2 = n - 1
        cur = len(A) - 1
        while idx1 >= 0 and idx2 >= 0:
            if A[idx1] > B[idx2]:
                A[cur] = A[idx1]
                idx1 -= 1
            else:
                A[cur] = B[idx2]
                idx2 -= 1
            cur -= 1
        if idx1 >= 0:
            while idx1 >= 0:
                A[cur] = A[idx1]
                cur -= 1
                idx1 -= 1
        if idx2 >= 0:
            while idx2 >= 0:
                A[cur] = B[idx2]
                cur -= 1
                idx2 -= 1
```