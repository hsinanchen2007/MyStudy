### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums = sorted(nums1 + nums2)
        if len(nums) % 2 != 0:
            return nums[int(len(nums) // 2)]
        else:
            return (nums[(len(nums) - 1) // 2] + nums[(len(nums) + 1) // 2]) / 2
```