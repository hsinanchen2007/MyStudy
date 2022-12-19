# 思路
1. 遍历nums，在下标i处的原数字为abs(nums[i]),定义j = abs(nums[i]) - 1， 当j < len(nums),则对j处的数乘-1，否则从extra数组中删去abs(nums[i]), 代表abs(nums[i])位于原数组中。
2. 再次遍历nums，当下标i处的数字nums[i] < 0，则数字i + 1不在原数组中。添加extra内剩余元素即为结果
```
class Solution:
    def missingTwo(self, nums: List[int]) -> List[int]:
        n = len(nums)
        extra = [n + 1, n + 2]
        for num in nums:
            i = abs(num) - 1
            if i < n:       nums[i] *= -1
            else:           extra.remove(abs(num))
        res = []
        for i in range(n):
            if nums[i] < 0: nums[i] *= -1
            else:           res.append(i + 1)
        return res + extra
```
