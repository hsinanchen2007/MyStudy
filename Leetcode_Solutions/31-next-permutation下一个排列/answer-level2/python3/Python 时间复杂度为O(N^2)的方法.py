#### 说明：
 - 在不知道公式和查看百科的情况下推导出来，要点和官方题解的算法是一致的，都是去寻找“第一个减量值”和“反方向上第一个刚好比减量值大的值”。
 - 差别在于官方题解巧妙的使用了邻值对比；而自己使用的是暴力遍历。虽说听起来好像就差一点，但实际上在两个方法之间，数学思维和敏锐度还差了一大截，只能自叹不如了。
 - 解法仅作参考，如果有同感者，望共勉之。
#### 代码：
```Python
from typing import List


class Solution:

    def __init__(self):
        self._steps = 0

    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        for i in range(len(nums) - 1, 0 - 1, -1):
            # print('1. nums[i:] -', nums[i:])
            for k in range(len(nums[i:])):
                # print('2. nums[i:len(nums) - k]', nums[i:len(nums) - k])
                check_nums = nums[i:len(nums) - k]
                swap_index = self._get_swapable_index(check_nums)
                if swap_index != -1:
                    # self._sort(check_nums, swap_index)
                    # 使用交换值更新原数组
                    nums[i:len(nums) - k] = check_nums
                    # 排序
                    self._sort(nums, i + 1)
                    return
        print(self._steps)
        nums.sort()

    def _get_swapable_index(self, nums: List[int]) -> int:
        """获得可交换值在数组的索引值；如果没有交换值，返回-1"""
        # print('before swap', nums)
        length = len(nums)
        for i in range(length - 2, -1, -1):
            self._steps += 1
            if nums[length - 1] > nums[i]:
                nums[length - 1], nums[i] = nums[i], nums[-1]
                # print('after swap:', nums, ', index:', i)
                return i
        return -1

    def _sort(self, nums: List[int], start: int) -> None:
        # print('before sort:', nums[start:], ', start:', start)
        nums[start:] = sorted(nums[start:])
        # print('after sort', nums[start:])
```