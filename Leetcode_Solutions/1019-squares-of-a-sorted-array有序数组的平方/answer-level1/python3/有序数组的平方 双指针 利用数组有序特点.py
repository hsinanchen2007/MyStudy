### 解题思路

### 代码

```python3
class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
        for i,c in enumerate(A):
           A[i] = c**2
        i = 0
        j = len(A) - 1
        result = []
        while i <= j:
            if A[i] <= A[j]:
                result.append(A[j])
                j -= 1
            else:
                result.append(A[i])
                i += 1
        return result[::-1]
```