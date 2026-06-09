# 假设题目要求返回删除重复数之后的列表：2个数的滑动窗口
```
class Solution(object):
    def removeDuplicates(self, nums):
        left, right = 0, 1
        for num in nums[1:]:
            if nums[right] == nums[left]:
                nums.pop(left)
            else:
                right += 1
                left += 1
        return len(nums)
```
