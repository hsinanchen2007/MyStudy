####  方法1：二分查找

| 时间复杂度 | 空间复杂度 |
| :--------: | :--------: |
|  O(logn)   |    O(l)    |

**基本思路：**

> 如代码注释，根据旋转数组的特点进行二分查找。

**代码：**

```python []
class Solution:
    def findMin(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1

        # 找旋转点
        # 1. 如果某半边数组仍为旋转数组(头元素大于尾元素)，则最小值在这半边；
        # 2. 如果两半边数组均为有序数组，则最小值为左半边数组的头元素。
        while l < r:
            m = (l + r) // 2

            if nums[l] >= nums[m] >= nums[r]:  # 完全逆序
                return nums[r]
            elif nums[m] > nums[r]:  # 后半边旋转，前半边有序
                l = m + 1
            elif nums[l] > nums[m]:  # 前半边旋转，后半边有序
                r = m  # 没有减1是为了考虑当前元素就是旋转点的情况
            else:  # 完全有序(nums[l] < nums[mid] < nums[r])
                return nums[l]
        return nums[l]
```