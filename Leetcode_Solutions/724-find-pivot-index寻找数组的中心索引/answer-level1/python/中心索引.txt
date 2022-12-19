"""
给定一个整数类型的数组 nums，请编写一个能够返回数组“中心索引”的方法。
我们是这样定义数组中心索引的：数组中心索引的左侧所有元素相加的和等于右侧所有元素相加的和。
如果数组不存在中心索引，那么我们应该返回 -1。如果数组有多个中心索引，那么我们应该返回最靠近左边的那一个。
"""
```
class Solution(object):
    def pivotIndex(self, nums):
        len_nums = len(nums)
        for k,v in enumerate(nums):
            left, right = nums[0:k], nums[k+1:len_nums]
            if sum(left) == sum(right):
                return k
        return -1

```
