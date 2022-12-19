class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if target not in nums:
            return [-1,-1]
        else:
            start=nums.index(target)
            if target not in nums[start+1:len(nums)]:
                return [start,start]
            else:
                x=nums[start+1:len(nums)]
                y=x[::-1]
                end=start+1+len(y)-1-y.index(target)
                return [start,end]