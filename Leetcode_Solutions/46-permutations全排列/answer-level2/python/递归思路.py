class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums)<2:
            return [nums]
        res = []
        for i in range(len(nums)):
            ans = [[nums[i]]+j for j in self.permute([num for num in nums if num != nums[i]])]
            res +=ans
        return res

执行用时 :24 ms, 在所有 Python 提交中击败了86.89%的用户
内存消耗 :12.1 MB, 在所有 Python 提交中击败了6.26%的用户