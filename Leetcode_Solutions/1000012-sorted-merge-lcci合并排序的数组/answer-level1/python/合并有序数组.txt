### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def merge(self, A, m, B, n):
        """
        :type A: List[int]
        :type m: int
        :type B: List[int]
        :type n: int
        :rtype: None Do not return anything, modify A in-place instead.
        """
        pa, pb = m - 1, n - 1
        cur = m + n -1
        while pa >= 0 or pb >= 0:
            a_val, b_val = A[pa] if pa != -1 else None, B[pb] if pb != -1 else None
            if a_val is None:
                A[cur] = b_val
                pb -= 1
            elif b_val is None:
                A[cur] = a_val
                pa -= 1
            elif a_val > b_val:
                A[cur] = a_val
                pa -= 1
            else:
                A[cur] = b_val
                pb -= 1
            cur -= 1
```