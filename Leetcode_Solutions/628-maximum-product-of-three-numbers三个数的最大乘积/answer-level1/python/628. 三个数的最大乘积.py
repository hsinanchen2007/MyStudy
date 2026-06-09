### 解题思路
第一步，将数组排序
第二步，分类讨论，如果数组中最后三个数都是正数或者都是负数，那么数组中乘积最大的三个数就是最后三个
第三步，分类讨论，如果数组中最后三个数有正有负（负数一定在正数前面，因为排序了），那么乘积最大的三个数是最后一个数和第一个数，第二个数的乘积
### 代码

```python
class Solution(object):
    def maximumProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = sorted(nums)

        a = nums[-1] * nums[-2] * nums[-3]
        b = nums[-1] * nums[0] * nums[1]
        
        res = max(a, b)
        
        return res
```