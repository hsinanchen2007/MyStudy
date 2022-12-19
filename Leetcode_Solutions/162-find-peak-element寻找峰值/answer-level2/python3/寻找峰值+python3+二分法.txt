####  方法1：二分法

| 时间复杂度 | 空间复杂度 |
| :--------: | :--------: |
|  O(logn)   |    O(l)    |

**基本思路：**

> 采用二分法确定峰值所在位置。
>
> - 如果当前`nums[i]>nums[i-1] and nums[i]>nums[i+1]  `，说明当前就是峰值。
> - 如果当前值小于前一个值，说明左边必有峰值。
> - 如果当前值小于后一个值，说明右边必有峰值

**代码：**

```python []
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        # 峰值定义：nums[i-1] < nums[i] > nums[i+1]，代表nums[i]为峰值
        # nums[-1] = nums[n] = -∞， 说明峰值可能出现在首尾

        l, r = 1, len(nums)
        # 防止数组越界和边界值是峰值的情况
        nums = [float('-inf')] + nums + [float('-inf')]

        while l < r:
            m = (l + r) // 2
            if nums[m] > nums[m - 1] and nums[m] > nums[m + 1]:
                return m - 1  # 减1是因为前面对数组进行了预处理，下同
            elif nums[m] < nums[m - 1]:
                r = m - 1
            else:
                l = m + 1
        return l - 1
```