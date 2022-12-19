1. 遍历一次 `nums`，将索引 `i` 左侧所有数字和赋值给 `left_sum[i]`，并计算所有数字总和 `s`；
2. 第二次遍历数组，由于 1 过程记录了左侧所有数字和，因此遍历到任何位置 `i` 时都可以得到：
    - 其左侧数字和 `left_sum[i]`
    - 其右侧数字和 `s - left_sum[i] - nums[i]`（即右侧数字和 = 所有数字总和 - 左侧数字和 - 当前元素）

对左右两侧数字和进行比较，如果相等就返回下标 `i`，若找不到则返回 `-1`。

```python
class Solution(object):
    def pivotIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left_sum = list()
        s = 0
        for n in nums:
            s += n
            left_sum.append(s - n)
            
        for i in range(len(nums)):
            left = left_sum[i]
            right = s - left - nums[i]
            if left == right:
                return i
        return -1
```