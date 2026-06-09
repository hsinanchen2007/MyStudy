![image.png](https://pic.leetcode-cn.com/f115756b8d445a428291cd8c9afd55f4ab8190c7171107ddd1ac2064c53e2fb6-image.png)


```
'''
枚举奇数位置做做较小值和偶数位置做较小值两种不同的情况中
开销较小的一种即可
'''

from typing import List
class Solution:
    def movesToMakeZigzag(self, nums: List[int]) -> int:
        n = len(nums)

        total1 = 0
        for i in range(0, n, 2):
            sub = 0
            if i-1 >= 0 and nums[i] >= nums[i-1]:
                sub = max(sub, nums[i] - nums[i-1] + 1)
            if i+1 < n and nums[i] >= nums[i+1]:
                sub = max(sub, nums[i] - nums[i+1] + 1)
            total1 += sub

        total2 = 0
        for i in range(1, n, 2):
            sub = 0
            if i - 1 >= 0 and nums[i] >= nums[i - 1]:
                sub = max(sub, nums[i] - nums[i - 1] + 1)
            if i + 1 < n and nums[i] >= nums[i + 1]:
                sub = max(sub, nums[i] - nums[i + 1] + 1)
            total2 += sub

        return min(total1, total2)
```
