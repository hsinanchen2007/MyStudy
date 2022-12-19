#### 简单的数学计算，元素为1，1的个数加一。将1的个数和最大的个数比较若大，则更新。遇到0，重新从0开始相加，计算1的连续个数
```
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        if len(nums) < 1:
            return None
        count = 0
        max_count = 0
        for i in range(len(nums)):
            if nums[i] == 0:
                count = 0
            else:
                count += nums[i]
            if count > max_count:
                max_count = count
        return max_count
```
