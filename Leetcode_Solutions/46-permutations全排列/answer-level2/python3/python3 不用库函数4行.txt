class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        k = [[]]
        for i in range(len(nums)):
            k = [x+[y] for x in k for y in nums if (y not in x)]
        return k