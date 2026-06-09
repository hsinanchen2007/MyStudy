- 开头出现`nums[0]>nums[1]`
- 中间比两边大
- 中间比两边小
- 结尾出现`nums[-2]>nums[-1]`
```
class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        pre=0
        count=0
        for p in range(1,len(nums)):
            if nums[pre]>nums[p]:
                count+=1
                if p==1:#开头出现
                    pre=1
                elif nums[p]>=nums[p-2]:#中间比两边大，中间指的是 nums[pre]
                    pre=p
                #下面是中间比两边小和结尾出现
                #else:
                    #continue
            else:
                pre=p
        return True if count<=1 else False
```
