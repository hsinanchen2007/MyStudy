### 解题思路
这道题如果只用递归会超时，关键是记忆化的形式，如果开一个数组的话大小为len(nums) \* (sum(nums) \* 2 + 1)，并且其中会有很多空位置，所以这里选择采用哈希表来存储中间结果。

### 代码

```python
class Solution(object):
    def findTargetSumWays(self, nums, S):
        """ 递归
        :type nums: List[int]
        :type S: int
        :rtype: int
        """
        length = len(nums)
        if length == 0:
            return 0
        note = {}
        def get_res(ind, temp):
            if ind == length:
                if temp == 0:
                    return 1
                else:
                    return 0
            if (ind, temp) in note:
                return note[(ind, temp)]
            res = get_res(ind + 1, temp + nums[ind]) + get_res(ind + 1, temp - nums[ind])
            note[(ind, temp)] = res
            return res
        return get_res(0, S)
```