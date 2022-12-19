class Solution:
    def moveZeroes(self, nums):
        """
        Do not return anything, modify nums in-place instead.
        """
        nums=sorted(nums)
        index=0
        for i in range(len(nums)):
            if nums[i]>0:
                index=i
                break
        nums=nums[index:]+nums[:index]
        return nums