class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        n = len(nums)
        if nums[0] > target:
            return 0
        if nums[n-1] < target:
            return len(nums)
        for i in range(n):
            if nums[i] == target:
                return i
            if target > nums[i] and target < nums[i+1] and i < n:
                return i + 1
