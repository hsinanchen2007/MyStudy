### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        for i in range(n):
            A[m+i] = B[i]
        A.sort()
```