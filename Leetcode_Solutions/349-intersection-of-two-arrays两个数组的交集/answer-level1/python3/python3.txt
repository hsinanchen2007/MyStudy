### 解题思路
此处撰写解题思路
用set()去重加减操作
### 代码

```python3
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        if len(nums1) <= len(nums2):
            nums1,nums2 = nums2,nums1
        return set(nums1)-(set(nums1)-set(nums2))
```