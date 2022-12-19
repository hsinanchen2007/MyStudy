### 解题思路
参考了两个解题的思路。仔细想想还是比较简单。
用递归的话更清晰。dp没有递归清晰。

### 代码

```python3
#  Copyright (c) 2019
#  @Author: xiaoweixiang
from typing import List


class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        nums = [1] + nums + [1]
        n = len(nums)
        dp = [[0] * n for _ in range(n)]
        '''
        参考了两个解题的思路。
        i是起始
        j是终点
        k是宽度，从2开始，层层迭代
        t是i+1~j-1
        '''
        for k in range(2, n):
            for i in range(n - k):
                j = i + k
                for t in range(i + 1, j):
                    dp[i][j] = max(dp[i][j], nums[i] * nums[t] * nums[j] + dp[i][t] + dp[t][j])
        return dp[0][n - 1]

```