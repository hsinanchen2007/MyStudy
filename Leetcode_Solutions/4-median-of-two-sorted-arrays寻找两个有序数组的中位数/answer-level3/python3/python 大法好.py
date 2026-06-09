
```
代码块
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums = nums1 + nums2
        nums.sort()
        size = len(nums)
        left = int((size-1) /2)
        right = left + ((size-1) % 2)
        return (nums[left]+nums[right]) / 2.0
```
    