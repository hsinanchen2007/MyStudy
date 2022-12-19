### 解题思路
![image.png](https://pic.leetcode-cn.com/e526bb41f0409694df93366676cbb643c038efa05b45992babce63aa5f59683f-image.png)

- 如果中间元素的值和下标相等,那么下一轮查找只需查找右半边
- 如果中间元素的值和下标不相等,并且它前面一个元素和它的下标相等,这意味着这个中间的数字正好是第一个值和下标不相等的元素,它的下标就是在数组中不存在的数字
- 如果中间元素的值和下标不相等,并且他前面的一个元素和它的下标不相等,这意味着下一轮只需要查找左半边即可

### 代码

```python
class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = [0]
        if not nums or len(nums) <= 0:
            return -1
        start = 0
        end = len(nums)-1
        length = len(nums)
        while start <= end:
            mid = (start + end) >> 1
            if nums[mid]!= mid:
                if mid == 0 or nums[mid-1] == mid-1:
                    return mid
                end = mid - 1
            else:
                start = mid + 1
            if start == length:
                return length

            


















```