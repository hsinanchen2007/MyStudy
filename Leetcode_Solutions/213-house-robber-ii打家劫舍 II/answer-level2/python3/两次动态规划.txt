### 解题思路
方法一：两次动态规划第一次为第一家到倒数第二家，第二次动态规划为第二家到最后一家，最后取两次动态规划的最大值

### 代码

```python3
class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0:
            return 0
        if n == 1:
            return nums[0]
        dp1 = [0 for _ in range(n)]
        dp2 = [0 for _ in range(n)]

        for i in range(1,n):
            dp1[i] = max(dp1[i-1],dp1[i-2]+nums[i])
        for j in range(0,n-1):
            dp2[j+1] = max(dp2[j],dp2[j-1]+nums[j])
        return max(dp1[-1],dp2[-1])
```