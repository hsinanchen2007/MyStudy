```
# -*- coding: utf-8 -*-

# Author: Cynthia

"""
    题目分析: 给定一个数组和一个目标值, 找到数组中3个元素加起来最接近目标值的和
    比如: [-1, 2, 1, -4]和1, 返回2; 假定结果唯一
    外层一个循环, 跳过重复遇到的值
    内层双指针, 也有优化空间, 如果左边两个加起来已经大于sum2, 退出内层循环; 右侧亦然
"""
from typing import List


class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:

        nums.sort()
        ans, ho = sum(nums[:3]), set()

        for i in range(len(nums)-2):

            if nums[i] in ho:
                continue
            ho.add(nums[i])

            sum2 = target-nums[i]
            l, r = i+1, len(nums)-1

            if nums[l]+nums[l+1] >= sum2:
                if (nums[l]+nums[l+1])-sum2 < abs(target-ans):
                    ans = nums[i]+nums[l]+nums[l+1]
                    continue

            if nums[r]+nums[r-1] <= sum2:
                if sum2-(nums[r]+nums[r-1]) < abs(target-ans):
                    ans = nums[i]+nums[r]+nums[r-1]
                    continue

            while l < r:
                if nums[l]+nums[r] == sum2:
                    return target
                if nums[l]+nums[r] < sum2:
                    if sum2-(nums[l]+nums[r]) < abs(target-ans):
                        ans = nums[i]+nums[l]+nums[r]
                    l += 1
                else:
                    if (nums[l]+nums[r])-sum2 < abs(target-ans):
                        ans = nums[i]+nums[l]+nums[r]
                    r -= 1
        return ans


# s = Solution()
# print(s.threeSumClosest([1,2,4,8,16,32,64,128], 82))

```
