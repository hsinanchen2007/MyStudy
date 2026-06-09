```
# -*- coding: utf-8 -*-

# Author: Cynthia

"""
    方法2, 外层同解法1, 内层双指针, 去重还是用set(tuple)
"""
from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        # 双指针法需要有序
        nums.sort()

        ans, ho = set(), set()

        for i in range(len(nums)-2):
            if nums[i] in ho:
                continue

            l, r, sums = i+1, len(nums)-1, 0-nums[i]

            # 最小的两个加起来都大于sums, 无需继续处理
            if nums[l]+nums[l+1] > sums:
                continue
            # 最大的两个加起来都小于sums, 无需继续处理
            if nums[r]+nums[r-1] < sums:
                continue

            while l < r:
                if nums[l]+nums[r] > sums:
                    r -= 1
                elif nums[l]+nums[r] < sums:
                    l += 1
                else:
                    g = [nums[i], nums[l], nums[r]]
                    g.sort()
                    ans.add(tuple(g))
                    l, r = l+1, r-1

            ho.add(nums[i])

        ans = [list(item) for item in ans]
        return ans


s = Solution()
print(s.threeSum([1, 2, 3, -1, -2, -3, 0, 8, 7]))
```
