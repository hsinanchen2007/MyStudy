### 解题思路
打卡

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        i = m-1
        j = n-1
        k = m+n-1
        while i >= 0 and j >= 0:
            if A[i] >= B[j]:
                A[k],A[i] = A[i],A[k]
                i -= 1
            else:
                A[k] = B[j]
                j -= 1
            k -= 1
        A[:j+1] = B[:j+1]
```