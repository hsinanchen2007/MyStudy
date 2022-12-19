思路：最小差值总是由数组中  **最小数+K** 与 **最大数-K**的差值 得到，最小差值最小为0.
```
class Solution:
    def smallestRangeI(self, A: List[int], K: int) -> int:
        A.sort()
        return max(A[-1]-A[0]-2*K,0)
```
