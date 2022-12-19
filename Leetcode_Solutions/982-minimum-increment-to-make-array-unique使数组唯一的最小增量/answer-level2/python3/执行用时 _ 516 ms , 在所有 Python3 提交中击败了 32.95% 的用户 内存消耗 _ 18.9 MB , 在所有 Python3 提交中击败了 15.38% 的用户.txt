### 解题思路
排序+搜索

### 代码

```python3
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        A.sort()
        res = 0
        for i in range(1,len(A)):
            if A[i] <= A[i-1]:
                res += A[i-1]-A[i]+1
                A[i] = A[i-1]+1
        return res
```