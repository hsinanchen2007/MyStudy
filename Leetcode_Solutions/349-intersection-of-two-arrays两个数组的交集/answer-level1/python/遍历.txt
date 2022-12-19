### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        res = []
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        for x in nums1:
            if x in nums2 and x not in res:
                res.append(x)
        return res
```