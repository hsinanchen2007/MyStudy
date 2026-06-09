### 解题思路
利用collections下的elements恢复原有元素

### 代码

```python3
import collections
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        return list((collections.Counter(nums1)&collections.Counter(nums2)).elements())
```