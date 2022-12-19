class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        l=[]
        if s==0:
            return 1
        else:
            for i in range(len(nums)):
                for j in range(1,len(nums)+1-i):
                    if sum(nums[i:i+j])>=s:
                        l.append(j)
            if l==[]:
                return 0
            return min(l)
