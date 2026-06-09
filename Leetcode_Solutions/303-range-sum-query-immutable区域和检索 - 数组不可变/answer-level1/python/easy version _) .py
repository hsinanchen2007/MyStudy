### 解题思路
此处撰写解题思路

### 代码

```python3
class NumArray:

    def __init__(self, nums: List[int]):
        if not nums:
            return 
        self.dp = [0] * (len(nums)+1)
        self.dp[1] = nums[0]
        for i in range(2, len(nums)+1):
            self.dp[i] = nums[i-1] + self.dp[i-1]
    def sumRange(self, i: int, j: int) -> int:
       return self.dp[j+1] - self.dp[i]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)
```