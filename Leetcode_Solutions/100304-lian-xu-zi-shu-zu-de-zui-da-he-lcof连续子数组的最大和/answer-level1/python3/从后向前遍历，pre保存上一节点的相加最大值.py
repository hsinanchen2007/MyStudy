class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxvalue = max(nums)
        pre = nums[-1]
        for i in range(len(nums)-2,-1,-1):
            if pre>0:
                pre = nums[i]+pre
            else:
                pre = nums[i]
            maxvalue = max(pre,maxvalue)
        return maxvalue