class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        for i in range(len(nums)-1):
            while i <len(nums)-1 and nums[i]==nums[i+1]:
                del nums[i+1]
        return len(nums)