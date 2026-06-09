### 解题思路
此处撰写解题思路

### 代码

```python3

class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        if not A or not B:
            return
        end = m + n - 1
        i = m - 1
        j = n - 1

        while i >= 0 and j >= 0:
            if A[i] >= B[j]:
                A[end] = A[i]
                i -= 1
            elif A[i] < B[j]:
                A[end] = B[j]
                j -= 1
            end -= 1
        while i >= 0:
            A[end] = A[i]
            i -= 1
            end -= 1
        while j >= 0:
            A[end] = B[j]
            j -= 1
            end -= 1


```