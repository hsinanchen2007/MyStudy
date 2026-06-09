只查找对角线. 仅需用一个int型变量.


```python
class Solution:
    def findLength(self, A: List[int], B: List[int]) -> int:
        """仅查找对角线, 将空间复杂度优化到O(1)
        """
        if not A or not B:
            return 0

        size_a = len(A)
        size_b = len(B)

        res = 0
        for row in range(size_a):
            i, j = row, 0
            t = 0
            while i < size_a and j < size_b:
                if A[i] == B[j]:
                    t += 1
                else:
                    t = 0
                i += 1
                j += 1
                if t > res:
                    res = t

        for col in range(size_b):
            i, j = 0, col
            t = 0
            while i < size_a and j < size_b:
                if A[i] == B[j]:
                    t += 1
                else:
                    t = 0
                i += 1
                j += 1
                if t > res:
                    res = t

        return res
```
