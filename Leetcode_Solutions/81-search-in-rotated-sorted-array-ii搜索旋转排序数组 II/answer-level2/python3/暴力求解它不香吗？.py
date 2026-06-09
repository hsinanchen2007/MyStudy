class Solution:

    def search(self, nums: List[int], target: int) -> bool:
        if(len(nums) == 0):
            return False
        for x in nums:
            if x == target:
                return True
        return False


