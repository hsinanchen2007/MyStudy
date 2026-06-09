维护两个数组就完事了嗷铁汁萌
```
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        t_min=[nums[0]]
        t_max=[nums[0]]
        for i in range(1,len(nums)) :
        #懒得判断正负了 直接丢进去一起滚
            t_max.append(max(nums[i],nums[i]*t_max[i-1],nums[i]*t_min[i-1]))
            t_min.append(min(nums[i],nums[i]*t_max[i-1],nums[i]*t_min[i-1]))
        return max(t_max)
```
