class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        nums.sort() #排序
        return nums[len(nums)//2] #因为大于n/2，返回中间那个