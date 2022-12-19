class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        sortedSetNums = sorted(list(set(nums)))
        length = len(sortedSetNums)
        if length  < 1:
            return
        elif length == 1:
            return sortedSetNums[0]
        elif length == 2:
            return sortedSetNums[1]
        else:
            return sortedSetNums[-3]