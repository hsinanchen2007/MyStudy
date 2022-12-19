class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}
        for i,j in enumerate(nums):
            if j in d:
                return [d[j], i]
            d[target-j]=i