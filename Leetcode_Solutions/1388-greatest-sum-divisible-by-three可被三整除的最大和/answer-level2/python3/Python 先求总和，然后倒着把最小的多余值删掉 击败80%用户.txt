![image.png](https://pic.leetcode-cn.com/7837421de916eaa0e2ed1a5b12a0ecdfe0707b2914a922c872cf26b7d2d7d864-image.png)


```
'''
先把所有数值和求出来，
如果对3取余数剩余1，选两个最小的对3取余为2的数值删掉，或者选一个最小对3取余为1的值删掉
如果对3取余数剩余2，选两个最小的对3取余为1的数值删掉，或者选一个最小对3取余为2的值删掉
'''

from typing import List
class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        l1 = sorted([x for x in nums if x % 3 == 1])
        l2 = sorted([x for x in nums if x % 3 == 2])

        total = sum(nums)
        if total % 3 == 0:
            return total
        elif total % 3 == 1:
            ans = 0
            if len(l1) > 0:
                ans = max(ans, total - l1[0])
            if len(l2) >= 2:
                ans = max(ans, total - l2[0] - l2[1])
            return ans

        else:
            ans = 0
            if len(l2) > 0:
                ans = max(ans, total - l2[0])
            if len(l1) >= 2:
                ans = max(ans, total - l1[0] - l1[1])
            return ans
```
