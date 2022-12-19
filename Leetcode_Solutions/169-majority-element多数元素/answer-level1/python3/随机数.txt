class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        import random
        n = 0
        while n <= 0:
            ind = random.randint(0, len(nums) - 1)
            n = 0
            for i in range(len(nums)):
                if nums[i] == nums[ind]:
                    n += 1
                else:
                    n -= 1
            
            if n > 0:
                return nums[ind]