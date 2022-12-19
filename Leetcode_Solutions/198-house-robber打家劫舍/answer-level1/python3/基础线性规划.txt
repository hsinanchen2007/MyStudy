### 解题思路
思路还是分解成一个个子问题，先帮它“解决”前面几个小问题，然后它就会了。

### 代码

```python
class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0

        maxAmount = [0]*len(nums)
        for i in range(len(nums)):
            if i == 0:
                maxAmount[0] = nums[0]
            elif i == 1:
                maxAmount[1] = max(
                    nums[0],
                    nums[1]
                )
            else:
                maxAmount[i] = max(
                    maxAmount[i-2] + nums[i],
                    maxAmount[i-1]
                )
        
        return max(maxAmount)


```