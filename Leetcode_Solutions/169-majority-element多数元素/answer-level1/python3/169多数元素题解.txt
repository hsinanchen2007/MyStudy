    def majorityElement(self, nums: List[int]) -> int:
        nums.sort()
        n=len(nums)//2
        return nums[n]
                