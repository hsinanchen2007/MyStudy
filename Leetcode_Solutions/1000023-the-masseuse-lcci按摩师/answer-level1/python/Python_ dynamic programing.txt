### 解题思路
打家劫舍基础版本。

### 代码
#### space O(n)
```python
class Solution:
    def massage(self, nums: List[int]) -> int:
        if not nums: return 0
        n = len(nums)
        if n <=2:
            return max(nums)
        dp = [0 for _ in range(n)]
        dp[0], dp[1] = nums[0], max(nums[:2])
        for i in range(2, n):
            dp[i] = max(dp[i-1], dp[i-2] + nums[i])
        return max(dp)
```
#### space O(1)
```python
class Solution:
    def massage(self, nums: List[int]) -> int:
        if not nums: return 0
        n = len(nums)
        if n <=2:
            return max(nums)
        dp = [nums[0], max(nums[:2])]
        for i in range(2, n):
            dp[i%2] = max(dp[~i%2], dp[i%2] + nums[i])
        return max(dp)
```