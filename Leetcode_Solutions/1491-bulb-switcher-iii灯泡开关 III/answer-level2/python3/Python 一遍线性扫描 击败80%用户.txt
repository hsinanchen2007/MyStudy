![image.png](https://pic.leetcode-cn.com/7f18b62dfad415a17bf856b9a249b7cdea7bf210d390c898e6d67f1e34e84f0a-image.png)


```
'''
动作到右进行遍历，维护已经扫过的部分中最大值，如果最大值等于当前的下标+1 那前面刚
扫过的部分是一个目标区间，统计合法区间的个数即可
'''

from typing import List
class Solution:
    def numTimesAllBlue(self, light: List[int]) -> int:
        max_val = -1
        ans = 0
        for i , val in enumerate(light):
            max_val = max(max_val, val)
            if max_val == i + 1:
                ans += 1

        return ans

```
