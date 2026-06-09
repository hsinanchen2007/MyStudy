```
class Solution:
    def findMissingRanges(self, nums: List[int], lower: int, upper: int) -> List[str]:
        ans=[]
        nums=[lower-1]+nums+[upper+1]
        for i in range(len(nums)-1):
            d=nums[i+1]-nums[i]
            if d==2:
                ans.append(str(nums[i]+1))
            elif d>2:
                ans.append(str(nums[i]+1)+'->'+str(nums[i+1]-1))
        return ans
```
