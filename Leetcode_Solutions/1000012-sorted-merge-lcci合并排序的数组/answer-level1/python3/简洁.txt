### 解题思路
“从数组的末端向前端移动”
原来是这个意思hhh

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        pa = m - 1
        pb = n - 1
        k = m + n
        while k > 0:
            k -= 1
            if pa == -1:
                A[k] = B[pb]
                pb -= 1
                continue
            if pb == -1:
                A[k] = A[pa]
                pa -= 1
                continue
            if A[pa] > B[pb]:
                A[k] = A[pa]
                pa -= 1
            else:
                A[k] = B[pb]
                pb -= 1
```