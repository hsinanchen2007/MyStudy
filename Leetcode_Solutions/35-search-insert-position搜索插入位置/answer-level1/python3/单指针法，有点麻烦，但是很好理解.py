class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        i = 0
        big = []
        small = []
        for i in range(len(nums)):
            if nums[i] == target:
                return i
            elif nums[i] < target:
                small.append(nums[i])
            elif nums[i] > target:
                big.append(nums[i])
        if len(small) == len(nums):
            return len(nums) 
        elif len(big) == len(nums):
            return 0
        elif len(small) + len(big) == len(nums):
            return len(small)