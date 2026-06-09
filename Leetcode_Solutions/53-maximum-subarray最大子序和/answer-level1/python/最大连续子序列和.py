class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        pre_max = -float('inf')
        all_max = -float('inf')
        for item in nums:
            pre_max = max(pre_max + item, item)
            all_max = max(all_max, pre_max)
            
        return all_max
