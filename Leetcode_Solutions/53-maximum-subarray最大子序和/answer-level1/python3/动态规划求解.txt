动态规划求解

已知前面i项的最大值：
i+1可能的情况：
i+1的最大等于 i的最大
i+1的最大 等于i的最大加上nums[i]
这个通过 max(ans, value)实现

class Solution():
    def maxSubArray(self, nums):
        if not nums:
            return None
        ans = nums[0]
        value = nums[0]
        for i in range(1, len(nums)):  
            if value <= 0:
                value = nums[i]
            else:
                value += nums[i]
            ans = max(ans, value)
        return ans