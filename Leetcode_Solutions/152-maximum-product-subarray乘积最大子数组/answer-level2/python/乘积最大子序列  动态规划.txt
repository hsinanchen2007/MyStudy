### 解题思路

### 代码

```python
class Solution(object):
    def maxProduct(self, nums):
       #由于数组中存在负数，所以可能存在将最大变为最小，最小变为最大的可能
       #因此需要维护最大值与最小值
        cur_max = 1
        cur_min = 1
        max_pro = nums[0]
        for i in range(len(nums)):
            if nums[i] < 0: #遇到负数，将当前最大值与最小值交换，再进行后续处理
                cur_max,cur_min = cur_min,cur_max
            cur_max = max(cur_max*nums[i],nums[i])
            cur_min = min(cur_min*nums[i],nums[i])
            max_pro = max(max_pro,cur_max)
        return max_pro
```