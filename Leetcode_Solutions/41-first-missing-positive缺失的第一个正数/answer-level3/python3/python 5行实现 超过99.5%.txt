class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        if len(nums) <= 0 or max(nums) <= 0 :return 1
        for i in range(1,max(nums)+1):
            if i not in nums :return i 
            else:continue
        return max(nums)+1
