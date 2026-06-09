
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        i=len(nums)-1
        if(i==0):
            return True
        c=len(nums)-2
        p=0
        while(i>0 and c>=0):
            if(i-c<=nums[c]):
                i=c
                c=i-1
            else:
                c=c-1
        if(i==0):
            return True
        else:        
            return False
                            