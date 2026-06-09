### 解题思路
先排序，确保后一个比前一个大一，记录增量

### 代码

```python3
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        A.sort()
        ans=0
        for i in range(1,len(A)):
            if A[i]<=A[i-1]  :
                t=A[i]
                A[i]=A[i-1]+1
                ans += A[i-1]+1-t
        return ans


```