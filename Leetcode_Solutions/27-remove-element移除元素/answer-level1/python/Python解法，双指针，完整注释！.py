### 解题思路
左右下标移动，原地交换值，空间复杂度O(1)，时间复杂度O(n)。

### 代码

```python
class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        l = len(nums)   # 原数组长度
        new_len = l     # 移除元素后的新数组长度
        right = l - 1   # 数组右边有效下标

        for i in range(0, l):
            # 左下标遇到右下标，说明已经遍历了整个数组
            if i > right:
                break

            # 左下标找到等于val的元素
            if nums[i] == val:
                # 从右边找一个不等于val的元素
                # 如果右边的元素也等于val，则right下标左移
                # 并且新长度减一
                while right > i and nums[right] == val:
                    right -= 1
                    new_len -= 1

                # 找到右边不等于val的元素后，原地交换值
                nums[i], nums[right] = nums[right], nums[i]
                right -= 1
                new_len -= 1

        return new_len
```