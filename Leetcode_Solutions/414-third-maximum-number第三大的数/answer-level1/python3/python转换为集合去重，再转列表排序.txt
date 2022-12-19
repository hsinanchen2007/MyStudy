class Solution(object):
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        se = set(nums)
        nums = list(se)
        nums.sort()
        n = len(nums)
        if n > 2:
            return nums[-3]
        else:
            return nums[-1]

