
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            k = nums[i]
            while k in nums[i+1:]:
                nums.remove(k)
            if nums[i] == nums[-1]:
                break
        return len(nums)