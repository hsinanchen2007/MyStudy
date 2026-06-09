提交时间	提交结果	执行用时	内存消耗	语言
10 分钟前	通过	32 ms	12.9 MB	Python3
超过 99.88 % 的 Python3 时间记录

```
class Solution:
    def rob(self, nums: List[int]) -> int:
        if nums==[]: return 0
        b, c = 0, nums[0]
        for j in nums[1:]:
            a, b = b, c
            c = max(b, a + j)
        return c
```