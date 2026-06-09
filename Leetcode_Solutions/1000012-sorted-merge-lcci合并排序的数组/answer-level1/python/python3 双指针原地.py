### 解题思路
从后向前比较大小

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        p1, p2, p = m - 1, n - 1, m + n - 1
        while p1 >= 0 and p2 >= 0:
            if A[p1] < B[p2]:
                A[p] = B[p2]
                p2 -= 1
            else:
                A[p] = A[p1]
                p1 -= 1
            p -= 1
        A[:p2+1] = B[:p2+1]
        
```