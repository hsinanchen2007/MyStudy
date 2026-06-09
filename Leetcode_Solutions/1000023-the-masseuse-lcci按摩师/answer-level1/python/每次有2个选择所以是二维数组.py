### 解题思路
1、dp[i]代表第i次达到最好；
2、dp[i]需要用dp[i-1]算出来；
3、但是每次都有两个选择，要么用要么不用，因此数组需要扩展为dp[i, 2]其中dp[i,0]代表本次不接单，dp[i, 1]代表本次接单；


### 代码

```python
import numpy as np


class Solution(object):
    def massage(self, nums):
        """
        arr[i, 0]代表第i次没有接单
        arr[i, 1]代表第i次接单了
        :type nums: List[int]
        :rtype: int
        """
        if len(nums)==0:
            return 0
        n = len(nums)
        arr = np.zeros((n, 2))
        arr[0, 0] = 0
        arr[0, 1] = nums[0]
        for i in range(1, n):
            # 第i次不接单，等于第i-1不接单和第i-1次接单的最大值
            arr[i, 0] = max(arr[i-1, 0], arr[i-1, 1])
            # 第i次接单，那么第i-1次只能不接单
            arr[i, 1] = arr[i-1, 0] + nums[i]
        return int(max(arr[n-1, 0], arr[n-1, 1]))
```