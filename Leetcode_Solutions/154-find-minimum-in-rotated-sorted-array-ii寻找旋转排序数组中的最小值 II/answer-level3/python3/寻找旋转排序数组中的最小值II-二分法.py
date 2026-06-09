### 解题思路
本题与[第153题](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)的不同在于数组`nums`中可能存在重复整数，因此可能在旋转之后使得`nums[left]==nums[right]`，此时就无法通过将`nums[mid]`与`nums[left]`和`nums[right]`比较大小来判断最小值在数组的哪一边了，这时只能通过遍历`nums[left:right+1]`中的所有整数找到最小值。

### 代码

```python3
class Solution:
    def findMin(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return None
        if nums[0] < nums[-1]:
            return nums[0]
        
        left, right = 0, len(nums)-1
        while right-left > 1:
            if nums[left] == nums[right]:
                return min(nums[left:right+1])
            mid = (left+right)>>1
            if nums[mid]>=nums[left]:
                left = mid
            elif nums[mid]<=nums[right]:
                right = mid

        return nums[left] if nums[left]<nums[right] else nums[right]

```