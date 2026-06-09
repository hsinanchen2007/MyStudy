### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        while n > 0: A[m+n-1], m, n = (A[m-1], m-1, n) if m and A[m-1] > B[n-1] else (B[n-1], m, n-1)
```