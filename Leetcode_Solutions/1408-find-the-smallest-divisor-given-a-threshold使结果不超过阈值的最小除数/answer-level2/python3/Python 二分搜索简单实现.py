![image.png](https://pic.leetcode-cn.com/ff44f49e12dbfbf146256c1639d4e52ab72cc62fcbecc96b2644092b3ed0d967-image.png)


```

'''
二分搜索最小的除数
'''

from typing import List
class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        l, r = 1, max(nums)

        ans = -1
        while l <= r:
            m = l + (r - l) // 2
            total = sum([val // m if val % m == 0 else (val // m) + 1 for val in nums])
            if total <= threshold:
                ans = m
                r = m - 1
            else:
                l = m + 1
        return ans
```
