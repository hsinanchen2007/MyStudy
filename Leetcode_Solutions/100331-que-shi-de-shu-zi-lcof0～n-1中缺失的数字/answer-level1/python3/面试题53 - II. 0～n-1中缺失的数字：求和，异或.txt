### 方法一，求和：

```python []
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        return ((len(nums) + 1) * len(nums) // 2) - sum(nums)
```

### 方法二，异或：

```python []
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        ans = 0
        for i in range(len(nums)):
            ans ^= i ^ nums[i]
        return ans ^ len(nums)
```