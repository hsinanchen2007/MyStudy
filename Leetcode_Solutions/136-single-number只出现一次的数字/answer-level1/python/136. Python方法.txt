### 解题思路
官方题解的最后两种方法很有趣。
（1）数学方法。2 * sum(set(nums)) - sum(nums)
（2）异或运算。两个一样的数字异或结果为0 。

### 代码

```python
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = 0
        for num in nums:
            res ^= num
        return res
```