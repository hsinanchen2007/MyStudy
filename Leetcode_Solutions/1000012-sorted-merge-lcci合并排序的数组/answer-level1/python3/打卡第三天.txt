### 解题思路
如代码

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        idx, idxA, idxB = m+n-1, m-1, n-1
        while(idx >= 0):
            if(idxB < 0):
                break
            
            if(A[idxA] <= B[idxB] or idxA < 0):
                A[idx] = B[idxB]
                idxB -= 1
            else:
                A[idx] = A[idxA]
                idxA -= 1
            
            idx -= 1



```