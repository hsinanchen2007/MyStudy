### 解题思路
很容易想到的**从后往前**填充A数组的空间，一次遍历和修改空间即可。

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        ptrA = m - 1
        idxA = m - 1
        idxB = n - 1
        # traverse from the end
        while idxA >= 0 and idxB >= 0:
            if A[idxA] >= B[idxB]:
                A[ptrA] = A[idxA]
                idxA -= 1
            else:
                A[ptrA] = B[idxB]
                idxB -= 1
            ptrA -= 1
        
        if idxA < 0: # it means array A has been traversed
            A[:idxB+1] = B[:idxB+1]
        
        return A 
```