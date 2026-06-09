算法：增加一个辅助元素。
```python []
class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if not nums:
            return []
        nums.append(float('inf'))
        pre,cur,res= nums[0],nums[0],list()
        for i in range(1,len(nums)):
            if nums[i] - nums[i-1] != 1:
                if pre == cur:
                    res.append("%s"%pre)
                else: 
                    res.append("%s->%s"%(pre,cur))
                pre,cur = nums[i],nums[i]
            else:
                cur = nums[i]
        return res
```

