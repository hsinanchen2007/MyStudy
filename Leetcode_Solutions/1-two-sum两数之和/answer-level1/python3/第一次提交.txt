class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # 1、字典
        if len(nums) <= 1: return False
        d = {}
        for i, num in enumerate(nums):
            if target-num in d:
                return [d[target-num], i]
            d[num] = i