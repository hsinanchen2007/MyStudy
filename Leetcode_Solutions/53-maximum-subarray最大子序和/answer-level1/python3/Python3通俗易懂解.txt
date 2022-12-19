### 解题思路
O(N)时间.
i指针往前走, 遇到cur_sum > max_sum就更新max_sum.
更新完max_sum后, 再检查如果cur_sum < 0了, 那么cur_sum重置为0. 即由于之前的部分综合是负数, 我们可以舍弃了之前的数组部分.

### 代码

```python3
import sys

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_sum = -sys.maxsize  # 设置为一个极小值
        cur_sum = 0
        len_nums = len(nums)
        if len_nums == 1:
            return nums[0]
        for i in range(len_nums):
            cur_sum = cur_sum + nums[i]
            if cur_sum > max_sum:
                max_sum = cur_sum
            if cur_sum < 0:
                cur_sum = 0
        
        return max_sum

            
```