class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        set_item = set()
        for num in nums:
            if num in set_item:
                return num
            set_item.add(num)