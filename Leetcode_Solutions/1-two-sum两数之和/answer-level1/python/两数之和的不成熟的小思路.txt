### 解题思路
首先考虑列表里只有一个元素的情况：
    如果target == list[i] 直接返回 下标
如果列表中多元素的情况：
    判断target减去list[i] 的值是否在剩余列表中：
        如果在的话那么从列表中取值，使用list.index方法，同时会有一个问题如果是两个相同元素的和为tartget的话，则返回的下标不符合题意，所以需要在list.index方法中使用start和end选填参数来获取想同值中非list[i]的下标。


### 代码

```python
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i, v in enumerate(nums):
            if len(nums) == 1 and target - v == 0:
                return [i]
            elif target - v in nums[i + 1:]:
                return [i, nums.index(target - v, i + 1)]
```