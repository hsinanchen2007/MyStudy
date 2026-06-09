```
class Solution(object):
    def findUnsortedSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        lo,hi=0,0
        maxnum=nums[0]        
        for i in range(len(nums)):            
            while lo>=0 and nums[i]<nums[lo]:lo-=1      
            if lo==hi:lo=hi=i
            elif nums[i]<maxnum:hi=i       
            maxnum=max(maxnum,nums[i])
        return hi-lo
```
