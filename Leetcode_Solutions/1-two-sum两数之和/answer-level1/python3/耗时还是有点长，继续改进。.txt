class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        for i in range(n):
            if target - nums[i] in nums and i != nums.index(target - nums[i]):
                return [i,nums.index(target - nums[i])]