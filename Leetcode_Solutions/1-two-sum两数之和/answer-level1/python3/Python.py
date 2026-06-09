class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        lens = len(nums)
        for i in range(lens):
            temp = target - nums[i]
            if temp in nums and i != nums.index(temp) :
                return [i,nums.index(temp)]