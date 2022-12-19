class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        if len(nums)<=1 or len(set(nums))==len(nums):
            return False
        else:
            for i in range(len(nums)):
                if i+k+1<=len(nums):
                    a=set(nums[i:i+k+1])
                    if len(a)<len(nums[i:i+k+1]):
                        return  True
                else:
                    a=set(nums[i:len(nums)])
                    if len(a)<len(nums[i:len(nums)]):
                        return  True
        return False