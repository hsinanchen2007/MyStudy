先排序，因为是偶数，检验数组中间的两个数，每个数判断其左右两边是否存在和它相同的数，有就返回
```python
class Solution:
    def repeatedNTimes(self, A: List[int]) -> int:
        n = len(A) // 2
        A = sorted(A)
        for i in range(2):
            if A[n-1] == A[n] or A[n+1] == A[n]:
                return A[n]
            n = n-1
        
        