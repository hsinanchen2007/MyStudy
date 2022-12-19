![image.png](https://pic.leetcode-cn.com/b7dbd2124504f81e56efff1fb9389e6344042045bfd24520e0b2a0895c8339ff-image.png)


```
'''
分桶思想

如果区间里面的数字都是等间隔排列的，那最大的间隔值一定是最小的，这种情况下，任何
一个数值不论增大还是减小，都只可能会造成最大间隔变大，不可能让情况变更好，把这个
等间隔作为桶的大小，最大间隔一定比这个桶大小要大，所以分在一个桶里面的数值之间差值
不可能是最大间隔，最大间隔只可能产生在相邻的桶之间，一定值前一个桶的最大值和后一个
桶的最小值的差值，所以只需要维护每一个桶里面的最大值和最小值，最后把相邻的桶遍历
一遍即可，时间复杂度是线性的
'''

from typing import List
from sortedcontainers import SortedDict
class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        bucket = SortedDict() # k是bucket的起点，值是bucket中的最大值和最小值

        n = len(nums)
        if n <= 1:
            return 0

        max_val, min_val = nums[0], nums[0]
        for val in nums:
            max_val = max(max_val, val)
            min_val = min(min_val, val)

        if max_val == min_val:
            return 0

        buck_size = max(1, (max_val - min_val) // (n - 1))

        for val in nums:
            buck_idx = (val - min_val) / buck_size
            if buck_idx not in bucket:
                bucket[buck_idx] = [val, val]
            else:
                bucket[buck_idx][0] = min(bucket[buck_idx][0], val)
                bucket[buck_idx][1] = max(bucket[buck_idx][1], val)

        buck_list = bucket.values()
        ans = -1
        for i in range(len(buck_list) - 1):
            ans = max(ans, buck_list[i+1][0] - buck_list[i][1])
        return ans
```
