### 解题
分两种情况：
当前面的子数组和小于等于0时，当前元素的最大值是当前元素
当前面子数组和大于0时，当前元素的最大值是前面子数组和加上当前元素

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_sum_arr = [nums[0]]
        pre_max_sum = nums[0]
        for i in range(1, len(nums)):
            if pre_max_sum <=0:
                curr_max = nums[i]
                pre_max_sum = curr_max 
                max_sum_arr.append(curr_max)
            elif pre_max_sum >0:
                curr_max = pre_max_sum + nums[i]
                max_sum_arr.append(curr_max)
                pre_max_sum = curr_max 
        return max(max_sum_arr)

```