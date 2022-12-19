### 解题思路
> dp 递推公式为 dp[i] = max(dp[i-2]+nums[i], dp[i-1])
- 注意边界条件的处理呢， ```dp[0] = nums[0]; dp[1] = max(nums[:2])```

### 代码

```python3 [group1-标准dp]
class Solution:
    def massage(self, nums: List[int]) -> int:
        if not nums:
            return 0
        if len(nums) <= 2:
            return max(nums)
        dp = [0] * len(nums)
        dp[0] = nums[0]
        dp[1] = max(nums[:2])
        for i in range(2, len(nums)):
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])
        return dp[-1]
```

```python3 [group1-dp压缩]
class Solution:
    def massage(self, nums: List[int]) -> int:
        if not nums:
            return 0
        if len(nums) <= 2:
            return max(nums)
        first = nums[0]
        last = max(nums[:2])
        for i in range(2, len(nums)):
            curr = max(first + nums[i], last)
            first = last
            last = curr
        return curr
```


# 运行情况
```
执行用时 :24 ms, 在所有 Python3 提交中击败了99.40%的用户
内存消耗 :13.4 MB, 在所有 Python3 提交中击败了100.00%的用户
```