### 解题思路
有重复的都被消掉，最后留下的只有单个的数字。

### 代码

```python
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return nums[0]

        value = nums[0]
        for i in range(1, len(nums)):
            value = value ^ nums[i]
        
        return value

```