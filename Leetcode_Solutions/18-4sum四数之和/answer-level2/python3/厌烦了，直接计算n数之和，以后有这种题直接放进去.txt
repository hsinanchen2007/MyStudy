```
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
            if nums[i] + nums[i + 1] + nums[i + 2] > target:
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

    def my_n_Sum(self, nums: List[int], target: int, n: int) -> List[List[int]]:
        """
            求n数之和
        :param nums:
        :param target:
        :param n:
        :return:
        """
        if len(nums) < n:
            return
        nums.sort()
        # 如果最小的都比目标大那么直接返回
        # 如果最大的还没目标大那么直接返回
        if sum(nums[:n]) > target or sum(nums[-n:]) < target:
            return
        len1 = len(nums)
        result = list()
        for i in range(len1 - n + 1):
            if i > 0 and nums[i] == nums[i - 1]:  # 去重
                continue
            # 如果当前最小值大于目标值，可以结束了
            if sum(nums[i:i + n]) > target:
                break
            # 如果当前最大值小于目标值，进入下一个循环
            if nums[i] + sum(nums[-n + 1:]) < target:
                continue
            cur = nums[i]
            if n == 4:
                r = self.threeSum(nums[i + 1:], target - cur)
            else:
                r = self.my_n_Sum(nums[i + 1:], target - cur, n - 1)
            if r:
                for r1 in r:
                    result.append([cur] + r1)
        return result


if __name__ == '__main__':
    x = [1, 0, -1, 0, -2, 2]
    t = 0
    y = Solution().my_n_Sum(x, t, 4)
    print(y)

```
