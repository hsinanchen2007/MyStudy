```python
class NumArray:

    def __init__(self, nums):
        self.dp = nums[:]
        # self.dp[i]存储0~i的子序列和
        for i in range(1, len(self.dp)):
            self.dp[i] += self.dp[i - 1]
        

    def sumRange(self, i, j):
        return self.dp[j] - self.dp[i - 1] if i > 0 else self.dp[j]
```