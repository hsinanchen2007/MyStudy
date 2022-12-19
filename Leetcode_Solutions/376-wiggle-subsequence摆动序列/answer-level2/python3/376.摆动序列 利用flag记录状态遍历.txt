利用一个flag记录当前状态(上升或者下降)，在到下一个元素的时候，根据上一次的flag来判断这个元素和下一个元素是否满足条件(上次是上升，这次就是下降)
```
class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        if len(nums)<2:
            return len(nums)
        res = 1
        flag = None
        for i in range(len(nums)-1):
            # 判断第一次flag
            if not flag:
                if nums[i]>nums[i+1]:
                    flag = -1
                    res += 1
                elif nums[i]<nums[i+1]:
                    res += 1
                    flag = 1
                continue
            # 利用两个值的差乘以flag来判断是否满足条件
            if (nums[i]-nums[i+1])*flag > 0:
                res += 1
                flag = -flag
        return res      
```
