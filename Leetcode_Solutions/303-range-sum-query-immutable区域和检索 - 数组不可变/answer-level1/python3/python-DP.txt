### 解题思路
此处撰写解题思路

### 代码

```python3
class NumArray:

    def __init__(self, nums: List[int]):
        '''
        self.sum = [0]*(len(nums)+1)
        if nums:
            self.sum[0] = nums[0]
            for i in range(1,len(nums)):
                self.sum[i] = self.sum[i-1]+nums[i]
        '''
        self.dp = nums[:]
        for i in range(1,len(self.dp)):
            self.dp[i]+=self.dp[i-1]
    def sumRange(self, i: int, j: int) -> int:
        '''
        return self.sum[j]-self.sum[i-1] if self.sum else 0
        '''
        return self.dp[j]-self.dp[i-1] if i>0 else self.dp[j]

# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)
```