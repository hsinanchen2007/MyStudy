class Solution:

    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:

        return [sum([1 for item in nums if item < n]) for n in nums ]