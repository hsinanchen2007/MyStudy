**特例：[0,0],k=0,True; [0,1,0],k=0,False;[1,2,3],k=0,False**
```
class Solution(object):
    def checkSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        if len(nums)<2:
            return False
        sum_=0
        for i in range(len(nums)):
            sum_=nums[i]
            for j in range(i+1,len(nums)):
                sum_+=nums[j]
                if(k==0 and sum_==0) or (k!=0 and (sum_%k)==0):
                    return True
        return False
    
                
        
```
