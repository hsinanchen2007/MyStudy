### 解题思路
首先维护两个数组：左边最大数组和右边最小数组，分别可以通过一次遍历得到，然后使用两个指针分别从左右进行遍历，左指针需要满足右边最小都等于当前元素，右指针需要满足左边最大都等于当前元素，那么需要调整的元素的区间为(p, q)。
时间复杂度为O(N)。

### 代码

```python
class Solution(object):
    def findUnsortedSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        length = len(nums)
        if length == 0:
            return 0
        left_max = [nums[0]] + [0] * (length - 1) # 左边最大
        right_min = [0] * (length - 1) + [nums[-1]] # 右边最小
        for i in range(1, length):
            left_max[i] = max(left_max[i - 1], nums[i])
        for i in range(length - 2, -1, -1):
            right_min[i] = min(right_min[i + 1], nums[i])
        print(left_max)
        p = -1
        q = length
        while p < length - 1 and right_min[p + 1] == nums[p + 1]:
            p += 1
        while q > p + 1 and left_max[q - 1] == nums[q - 1]:
            q -= 1
        print(p, q)
        return q - p - 1
```