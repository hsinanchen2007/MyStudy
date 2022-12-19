### 解题思路
荷兰国旗问题，使用3个指针，p0代表当前元素，p1代表0的右边界，2代表2的左边界
当p0 <= p2时（如果p0 > p2说明遍历完毕）
如果nums[p0] == 0, 那么p0和p1指向的元素互换，p0和p1同时后移；
如果nums[p0] == 1, 那么p0后移；
如果nums[p0] == 2, 那么p0和p1指向的元素互换，p2前移；
### 代码

```python
class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        if len(nums) > 1:
            p0 = 0
            p1 = 0
            p2 = len(nums) - 1

            while p0 <= p2:
                if nums[p0] == 0:
                    if p1 != p0:
                        nums[p1], nums[p0] = nums[p0], nums[p1]
                    p1 += 1
                    p0 += 1
                    continue

                if nums[p0] == 1:
                    p0 += 1
                    continue

                if nums[p0] == 2:
                    nums[p2], nums[p0] = nums[p0], nums[p2]
                    p2 -= 1

        return nums
```