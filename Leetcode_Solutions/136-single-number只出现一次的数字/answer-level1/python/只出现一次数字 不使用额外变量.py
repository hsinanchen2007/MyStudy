只出现一次数字 不使用额外变量
```
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()

        while len(nums)>1:
            if nums[-1]==nums[-2]:
                nums.pop(-1)
                nums.pop(-1)
            else:
                nums.pop(-2)
                nums.pop(-2)
        return nums[0]
```
