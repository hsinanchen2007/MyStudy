### 解题思路

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        # 从后往前插
        pa, pb, r = m-1, n-1, len(A)-1
        while pa >= 0 and pb >= 0:
            if A[pa] >= B[pb]:
                A[r] = A[pa]
                pa -= 1
            else:
                A[r] = B[pb]
                pb -= 1
            r -= 1
        # A没插完, 不用管
        while pb >= 0:
            A[r] = B[pb]
            r -= 1
            pb -= 1
        
```