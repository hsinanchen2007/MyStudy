```
class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return float('-inf')

        # max result and current sum
        max_res = nums[0]
        cur_sum = nums[0]

        for i in range(1, len(nums)):
            if cur_sum > 0:
                max_res = max(max_res, cur_sum + nums[i])
                cur_sum += nums[i]
            # current sum<0 then abandom and start from the new postion
            else:   
                max_res = max(max_res, nums[i], cur_sum)
                cur_sum = nums[i]
        
        return max_res


```
