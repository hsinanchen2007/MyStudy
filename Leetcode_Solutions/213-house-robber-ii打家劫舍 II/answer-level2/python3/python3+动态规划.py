两次dp，dp1考虑从第一家偷到倒数第二家，dp2考虑从第二家偷到最后一家，最后比较dp1[-1]和dp2[-1]，取大的。
![UC截图20191201160059.png](https://pic.leetcode-cn.com/bd2442be675f079c9d33c8059de4e0986b926cda08e36be54e32be1ef6909a69-UC%E6%88%AA%E5%9B%BE20191201160059.png)
```
class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if not nums:
            return 0
        if n == 1:
            return nums[0]
        if n == 2:
            return max(nums)
        dp1 = [0 for _ in range(n-1)]
        dp2 = [0 for _ in range(n-1)]
        dp1[0] = nums[0]
        dp1[1] = max(nums[0],nums[1])
        for i in range(2,n-1):
            dp1[i] = max(dp1[i-1],dp1[i-2] + nums[i])
        dp2[0] = nums[1]
        dp2[1] = max(nums[1], nums[2])
        for i in range(2, n - 1):
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i+1])
        return max(dp1[-1],dp2[-1])

```
