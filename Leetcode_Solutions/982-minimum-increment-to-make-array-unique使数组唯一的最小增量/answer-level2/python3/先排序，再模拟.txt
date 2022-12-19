### 解题思路
先排序，再模拟，每个元素都要至少比前一个元素大一

### 代码

```python3
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        A.sort()
        res=0
        n=len(A)
        if n<=1:
            return res
        for i in range(1,n):
            if A[i]<=A[i-1]:
                res+=A[i-1]-A[i]+1
                A[i]=A[i-1]+1
        return res
        
```