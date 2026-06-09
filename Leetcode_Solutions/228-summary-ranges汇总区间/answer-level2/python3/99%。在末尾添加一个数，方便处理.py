```
class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        res=[]
        if len(nums)==0: return res

        # 末尾添加一个不连续的数，这样每个原数组元素都能“结算”
        nums.append(nums[0]-1)
        
        start=end=nums[0]
        for i in range(1, len(nums)):
            if nums[i]-1 == nums[i-1]:
                end = nums[i]
            else:
                if start==end:
                    res.append(str(start))
                else:
                    res.append(str(start)+"->"+str(end))
                start=end=nums[i]
        return res
```
