### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums = nums1 + nums2
        nums.sort()
        length = len(nums)
        if length % 2 == 0:
            num = (nums[length//2-1]+nums[length//2]) / 2
        else:
            num = nums[length//2]
        return num

```