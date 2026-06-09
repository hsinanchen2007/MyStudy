class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        temp = {}
        for num in nums:
            if num not in temp:
                temp[num] = 1
            else:
                return num
