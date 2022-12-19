### 解题思路
如下代码所示

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        i = 0
        j = 0
        lens = m+n
        while (j<n) and (i<m):
            if A[i]<=B[j]:
                i += 1
            else:
                for k in range(lens-2,i-1,-1):
                    A[k+1] = A[k]
                A[i] = B[j]
                i += 1
                m += 1
                j += 1
        if j<n:
            A[m:] = B[j:]
        return A
```