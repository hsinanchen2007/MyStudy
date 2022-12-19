解法：把元素的值作为下标，将下标对应的值取负，然后返回正数的下标
```
class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # 把元素的值作为下标，将下标对应的值取负，然后返回正数的下标
        # 元素可能已经为负数 abs(i)
        # 元素重复出现改变对应值　-abs(nums[abs(i) - 1])
        for i in nums:
            nums[abs(i) - 1] = -abs(nums[abs(i) - 1])
        return [k + 1 for k, v in enumerate(nums) if v > 0]
```
