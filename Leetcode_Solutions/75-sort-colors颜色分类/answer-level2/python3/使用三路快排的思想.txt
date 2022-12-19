```
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        z=-1#nums[0,z]==0
        t=len(nums) #nums[t:]== 2
        i=0
        while i<t:#因为nums[t]==2
            if nums[i]==0:
                z+=1 #因为有新0,z=z+1,此时nums[z]即为值为1的第一个
                nums[i],nums[z]=nums[z],nums[i] #
                i+=1 #因为此时nums[i]=1
            elif nums[i]==2:
                t=t-1#因为有新2,t=t-1,此时nums[t]未知，所以换过去后不需要i+=1
                nums[i],nums[t]=nums[t],nums[i]
                
            else:#nums[i]==0
                i=i+1
        return nums
       
```
