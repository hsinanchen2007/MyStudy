思路: 先将数组拉平, 在利用堆来查找前k个最小元素, 去最后一个元素即可
```
import heapq
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        array = [y for x in matrix for y in x]
        return heapq.nsmallest(k, array)[-1]

```
