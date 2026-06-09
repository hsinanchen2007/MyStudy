### 解题思路
如果前面的数据加上自身，大于自身，就更新；否则用自身就好了；

### 代码

```python
import numpy as np


class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp = [0] * len(nums)
        dp[0] = nums[0]
        for i in range(1, len(nums)):
            if nums[i] + dp[i - 1] > nums[i]:
                dp[i] = nums[i] + dp[i - 1]
            else:
                dp[i] = nums[i]
        return int(np.array(dp).max())
```