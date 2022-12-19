### 解题思路
先排序，再逐升

### 代码

```python3
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        n = len(A)
        if n == 0 or n == 1:
            return 0
        A.sort()
        acc = 0
        for i in range(1,n):
            if A[i] <= A[i - 1]:
                acc += A[i-1] - A[i] + 1
                A[i] += A[i-1] - A[i] + 1
        return acc

```