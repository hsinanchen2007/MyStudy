执行用时 : 48 ms , 在所有 Python3 提交中击败了 83.64% 的用户。
内存消耗 : 12.9 MB , 在所有 Python3 提交中击败了 97.60% 的用户。
想法其实很简单，就是讨论两种情况：偷第一家 or 最后一家，然后就可以干了。
```
class Solution:
    def rob(self, nums: List[int]) -> int:
        if nums == []:
            return 0
        if len(nums) <= 3:
            return max(nums)
        a = [0] * (len(nums) - 1)
        for i,j in enumerate(nums[1:]):
            if i == 0:
                a[0] = nums[1]
                continue
            a[i] = max(a[i - 1], a[i - 2] + j)
        maxv = a[-1]
        a = [0] * (len(nums) - 1)
        for i,j in enumerate(nums[:-1]):
            if i == 0:
                a[0] = nums[0]
                continue
            a[i] = max(a[i - 1], a[i - 2] + j)
        return max(a[-1], maxv)
```