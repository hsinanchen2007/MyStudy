类似383赎金信，用计数器。

```
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        from collections import Counter
        nums1=Counter(nums1)
        nums2=Counter(nums2)
        return list((nums1&nums2).elements())
```
