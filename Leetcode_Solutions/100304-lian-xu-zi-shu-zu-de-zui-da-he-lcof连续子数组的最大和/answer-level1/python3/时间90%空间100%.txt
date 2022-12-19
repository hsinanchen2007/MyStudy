### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if len(nums)==1:
            return nums[0]
        sum_list = [nums[0]]
        for num in nums[1:]:
            if num+sum_list[-1]>=num:
                sum_list.append(num+sum_list[-1])
            else:
                sum_list.append(num)
        return max(sum_list)
        
```