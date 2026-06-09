```
class Solution:
    def threeSumSmaller(self, nums:list, target: int) -> int:
        # nums.sort()
        nums=sorted(nums,reverse=True)
        count=0
        for i in range(len(nums)-1,1,-1):
            l,r=0,i-1
            while l<r:
                if nums[l]+nums[r]+nums[i]<target:
                    count+=r-l
                    r-=1
                else:
                    l+=1
        return count
```