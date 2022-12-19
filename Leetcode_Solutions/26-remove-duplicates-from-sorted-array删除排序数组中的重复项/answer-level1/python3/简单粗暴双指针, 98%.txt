class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0
        if len(nums) <= 1:
            len(nums)

        left, right = 1, 1
        while right < len(nums):
            if nums[right] != nums[right-1]:
                nums[left] = nums[right]
                left += 1
            right += 1
        return left