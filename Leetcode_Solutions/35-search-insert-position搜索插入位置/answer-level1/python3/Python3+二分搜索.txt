常规二分搜索，参考@liweiwei1419代码, 只是将循环条件还原到了普通的退出条件 left<=right,个人感觉好理解些
```
from typing import List

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        size = len(nums)
        if size == 0:
            return 0

        # 特判
        if nums[size - 1] < target:
            return size

        left = 0
        right = size - 1

        while left <=  right:
            mid = (left + right) >> 1
            # 严格小于 target 的元素一定不是解
            if nums[mid] < target:
                # 下一轮搜索区间是 [mid + 1, right]
                left = mid + 1
            elif nums[mid]==target:
                return mid
            else:
                right = mid - 1

        return left
```
