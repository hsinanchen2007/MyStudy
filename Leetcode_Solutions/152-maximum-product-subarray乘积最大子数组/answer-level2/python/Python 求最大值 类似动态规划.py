class Solution:
    def maxProduct(self, nums: List[int]) -> int:
##前一个位置的最大值最小值均有可能产生新的极值 所以我们每一位都计算一个max value 和min value
        res=nums[0]
        max_value=nums[0]
        min_value=nums[0]
        for i in range(1,len(nums)):
            tmp_max=max_value
            max_value=max(nums[i],max_value*nums[i],min_value*nums[i])
            min_value=min(nums[i],tmp_max*nums[i],min_value*nums[i])
            res=max(max_value,res)
        return res