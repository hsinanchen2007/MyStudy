python3 暴力法，从左到右遍历，把区间输出


```
class Solution:
    def findMissingRanges(self, nums: List[int], lower: int, upper: int) -> List[str]:
        if not nums:
            if upper >lower:
                return [str(lower)+"->"+str(upper)]
            elif upper == lower:
                return [str(lower)]
                
        ltem=[]
        if nums[0]-lower==1:
            ltem.append(str(lower))
        if nums[0]-lower>=2:
            ltem.append(str(lower)+"->"+str(nums[0]-1))


        for i in range(1,len(nums)):
            if nums[i]-nums[i-1]==2:
                ltem.append(str(nums[i-1]+1))
            elif nums[i]-nums[i-1]>2:
                ltem.append(str(nums[i-1]+1)+"->"+str(nums[i]-1))

        if upper-nums[-1]==1:
            ltem.append(str(upper))
        if upper-nums[-1]>=2:
            ltem.append(str(nums[-1]+1)+"->"+str(upper))
        return ltem
```
