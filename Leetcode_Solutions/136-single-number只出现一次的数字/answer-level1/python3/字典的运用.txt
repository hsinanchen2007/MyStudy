class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        for i, v in enumerate(nums):
            dict = {}

            for i in nums:
                if dict.get(i) is None:
                    dict[i] = 1
                else:
                    dict[i] = 2

            for k, v in dict.items():
                if v == 1:
                    return k