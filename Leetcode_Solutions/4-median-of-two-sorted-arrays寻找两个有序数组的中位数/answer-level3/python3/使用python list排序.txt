### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums = nums1 + nums2
        nums.sort()
        count = len(nums)
        half = int(count / 2)
        if count % 2 == 0:
            return (nums[half - 1] + nums[half]) / 2
        return nums[half]

```