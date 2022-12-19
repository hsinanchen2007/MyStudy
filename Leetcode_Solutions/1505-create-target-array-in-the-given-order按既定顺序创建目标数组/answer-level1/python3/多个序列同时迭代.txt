class Solution:

    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:

        target = []

        for i, n in zip(index, nums):

            target.insert(i, n)

        return target