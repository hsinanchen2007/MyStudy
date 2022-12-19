将除法式子看做整体，被除数只有一个，就是nums[0]，相当于对于某次输入是确定的,要想结果最大，除数最小即可。那只能是nums[1:]连除下去做除数～
```
class Solution:
    def optimalDivision(self, nums: List[int]) -> str:
        if len(nums)==1:
            return str(nums[0])
        if len(nums)==2:
            return str(nums[0])+"/"+str(nums[1])
        res=str(nums[0])+"/("
        for i in range(1,len(nums)-1):
            res+=str(nums[i])+"/"
        res+=str(nums[-1])+")"
        return res
```
