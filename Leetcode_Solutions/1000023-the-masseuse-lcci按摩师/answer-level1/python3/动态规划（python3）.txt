可以分两类情况考虑；
第一种 0 到 n-1 个数里面最大的组合，视为f_max(n-1), 计作 max_left；
第二种 0 到 n 的最大组合，但是必须包括第n个数字, 计作 max_right。
这样 f_max(n+1) = max(max_left + nums[n+1], max_right)
一次循环，时间复杂度O(n)，空间复杂度O(1)。

```
class Solution:
    def massage(self, nums: List[int]) -> int:
        length = len(nums)
        if length <= 0:
            return 0
        if length == 1:
            return nums[0]
        if length == 2:
            return max(nums[0], nums[1])
        max_l = nums[0]
        max_r = nums[1]
        for i in range(2, length):
            max_l, max_r = max(max_l, max_r), max_l + nums[i]
        return max(max_l, max_r)
```
