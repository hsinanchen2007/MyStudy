### 解题思路
贪心算法，每次都把最好的树叶（max_sum）拿在手里
用curr_sum去判断当前数字nums[i]是否直接大于前面数列的和，大于就替代。
再拿curr_sum与max_sum对比是否优于。
时间复杂度O(n):只遍历一次
空间复杂度O(1)：常数空间
### 代码

```python
class Solution(object):
    def maxSubArray(self, nums):
        curr_sum = max_sum = nums[0]
        for i in range(1,len(nums)):
            curr_sum = max(nums[i] , curr_sum+nums[i])
            max_sum = max(curr_sum,max_sum)
        return max_sum
```