### 解题思路
直接调用heapq的nsmallest进行计算

### 代码

```python
import heapq
class Solution(object):
    def smallestK(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: List[int]
        """
        return heapq.nsmallest(k,arr)
```