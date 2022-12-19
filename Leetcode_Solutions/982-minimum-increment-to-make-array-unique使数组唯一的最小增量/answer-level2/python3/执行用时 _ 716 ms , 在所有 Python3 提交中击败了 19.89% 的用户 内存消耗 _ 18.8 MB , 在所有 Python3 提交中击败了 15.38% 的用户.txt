### 解题思路
此处撰写解题思路
先排序，然后每一项与后一项比大小，如果不是递增的就给后面的那一项加k，使得后一项比前一项大1，累加k即可
### 代码

```python3
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        A.sort()
        ans=0
        for i in range(len(A)-1):
            if A[i]>=A[i+1]:
                k=A[i]-A[i+1]+1
                A[i+1]=A[i]+1
                ans=ans+k
        return ans
```