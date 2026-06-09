### 解题思路
sorted()

### 代码

```python3
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums = nums1 + nums2
        nums = sorted(nums)
        print(nums)
        nums_leth = len(nums)
        if nums_leth % 2 == 0:
            return (nums[(nums_leth//2)-1] + nums[nums_leth//2])/2
        else:
            return nums[(nums_leth//2)]
```