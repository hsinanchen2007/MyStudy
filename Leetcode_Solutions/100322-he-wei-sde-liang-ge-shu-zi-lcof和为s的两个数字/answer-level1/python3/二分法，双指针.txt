# 首先特判：
**如果target小于nums的最小值，直接返回空**
# 其次:
**如果target小于nums的中间值，右半边不可能存在，直接把范围缩小到左半边，加快速度！**
# 最后考虑一般情况：
**即中间值小于target的情况，这里用分别用左右指针寻找，直至最后找到和为target的两个指针，返回对应值的数组！**
```
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        if nums[0]>target: return 
        l,r=0,len(nums)-1
        while l<r:
            mid=(l+r)//2
            if nums[mid]>target:
                r=mid-1
            elif nums[mid]<target:
                while l<r:
                    if nums[l]+nums[r]<target:
                        l+=1
                    elif nums[l]+nums[r]>target:
                        r-=1
                    else: 
                        return [nums[l],nums[r]]
```
