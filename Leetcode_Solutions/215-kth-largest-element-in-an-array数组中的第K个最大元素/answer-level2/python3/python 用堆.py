### 解题思路
创建一个空间为k的最大堆，最后一个即是答案
### 代码

```
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:

        return heapq.nlargest(k,nums)[-1]
```