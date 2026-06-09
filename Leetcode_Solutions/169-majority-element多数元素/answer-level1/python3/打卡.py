class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        nums.sort()
        l = len(nums)
        l = l//2
        return(nums[l])