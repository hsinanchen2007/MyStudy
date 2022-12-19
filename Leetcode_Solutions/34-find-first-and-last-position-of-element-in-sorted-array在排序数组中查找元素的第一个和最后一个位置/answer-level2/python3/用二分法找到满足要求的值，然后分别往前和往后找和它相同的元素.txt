```
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if not nums:
            return [-1,-1]
        l=0
        r=len(nums)-1
        while l<=r:
            m=l+(r-l)//2
            if nums[m]<target:
                l=m+1
            elif nums[m]>target:
                r=m-1
            else:
                a=b=m
                while a>0 and nums[a-1]==nums[m]:
                    a-=1
                while b < len(nums)-1 and nums[b+1] == nums[m]:
                    b+=1
                return [a,b]
        return [-1, -1]
```
