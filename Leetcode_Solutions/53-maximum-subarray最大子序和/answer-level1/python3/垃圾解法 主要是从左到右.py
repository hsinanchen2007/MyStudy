一开始选择'left+current'的方式 试了好久
后面决定换成'current+right'

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        temp=0
        max=nums[0]
        for i in range(len(nums)):
            temp+=nums[i]
            if max<temp :
                    max=temp
            if temp<0:
                    temp=0
        return max