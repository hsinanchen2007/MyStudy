### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        if len(A) == 0:return 0
        ans = 0
        A.sort()
        for i in range(1, len(A)):
            if A[i] <= A[i-1]:
                ans = ans + A[i-1]-A[i]+1
                A[i] = A[i-1]+1
        return ans
```