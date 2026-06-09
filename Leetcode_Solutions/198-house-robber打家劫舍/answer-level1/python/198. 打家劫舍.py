是其实跟爬楼梯问题一样的
开始是选择(1,3) 还是(1,4) 返过来的解决方案就是 
最后一步 = fn + max(fn-1, fn-2)

```
class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        _len = len(nums)
        if not nums: return 0
        if _len < 2: return max(nums)
        if _len == 3: return max(nums[0] + nums[2], nums[1])

        # 问题其实是L(n) = fn + max(fn-1, fn-2)
        _max, L = 0, nums[0:2] + [0] * (_len - 2)
        for i in range(2, _len):
            L[i] = nums[i] + max(L[i - 2], L[i - 3])
        return max(L)
```
