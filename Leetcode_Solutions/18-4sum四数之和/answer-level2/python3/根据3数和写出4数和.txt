### 解题思路
此处撰写解题思路

### 代码

```python3
from typing import List


class Solution:
    def threeSum(self, nums: List[int], target: int) -> List[List[int]]:
        result = list()
        len1 = len(nums)
        if len1 < 3:
            return result
        # nums.sort()  是排序好的  不需要再排序
        # 如果最大的还没目标大就返回
        if sum(nums[-3:]) < target:
            return result
        # 如果最小值大于目标值就返回
        if sum(nums[:3]) > target:
            return result
        for i in range(len1 - 2):
            # 当前的最大值
            if nums[i] + nums[-1] + nums[-2] < target:
                continue
            # 当前的最小值
            if sum(nums[i:i + 3]) > target:
                continue
            if i > 0 and nums[i] == nums[i - 1]: continue  # 去重
            now_n = nums[i]
            left, right = i + 1, len1 - 1
            while left < right:
                sum_three = now_n + nums[left] + nums[right]
                if sum_three == target:
                    result.append([now_n, nums[left], nums[right]])
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1
                    left, right = left + 1, right - 1
                elif sum_three > target:
                    right -= 1
                else:
                    left += 1
        return result

    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        if len(nums) < 4:
            return
        result = list()
        nums.sort()
        # 如果最小的都比目标大那么直接返回
        # 如果最大的还没目标大那么直接返回
        if sum(nums[:4]) > target or sum(nums[-4:]) < target:
            return
        len1 = len(nums)
        result = list()
        for i in range(len1 - 3):
            if i > 0 and nums[i] == nums[i - 1]:  # 去重
                continue
            # 获取当前最小值，如果最小值比目标值大，根本不需要计算了
            if sum(nums[i:i + 4]) > target:
                break
            # 获取当前最大值，如果比目标值小，则进入下次循环
            if nums[i] + nums[-1] + nums[-2] + nums[-3] < target:
                continue

            cur = nums[i]
            r = self.threeSum(nums[i + 1:], target - cur)
            if r:
                for r1 in r:
                    result.append([cur] + r1)
        return result

```