```
# -*- coding: utf-8 -*-

# Author: Cynthia

"""
    题目分析: 给定一个数组, 找到所有和等于0的组合
"""
"""
    方法1, 借鉴两个加和时的思路, hash, 外层循环, 中间的认为是两个数加和
"""
from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:

        # 外层哈希ho, 用于最外层的去重, 避免重复遍历
        # 结果哈希ans, 利用{(), ()}去重 (注意, list, set都不能hash, 只有tuple可以)
        ans, ho = set(), set()
        for i in range(len(nums)):
            if nums[i] in ho:
                continue

            h = set()
            for j in range(i+1, len(nums)):
                if -nums[i]-nums[j] in h:
                    l = [nums[i], nums[j], -nums[i]-nums[j]]
                    l.sort()
                    ans.add(tuple(l))
                h.add(nums[j])

            ho.add(nums[i])

        ans = [list(item) for item in list(ans)]
        return ans


print(Solution().threeSum([-1, 0, 1, 2, -1, -4]))
```
