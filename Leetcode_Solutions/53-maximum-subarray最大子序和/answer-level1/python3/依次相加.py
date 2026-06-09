### 解题思路
此处撰写解题思路
1. 依次相加，构建两个中间变量，一个记录当前时刻最大值，另一个记录整体的最大值
### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if len(nums) < 2:
            return nums[0]
        cur_sum = max_sum = nums[0]
        for i in range(1, len(nums)):
            num = nums[i] + cur_sum 
            if num > nums[i]:
                cur_sum = num
            else:
                cur_sum = nums[i]
            if cur_sum > max_sum:
                max_sum = cur_sum
        return max_sum
    

```