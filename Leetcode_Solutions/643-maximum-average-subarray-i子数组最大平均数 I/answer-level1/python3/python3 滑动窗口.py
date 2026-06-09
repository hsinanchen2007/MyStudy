### 解题思路
滑动窗口求和
但是时空复杂度不好，不知道有没有别的好一点的方法，欢迎赐教

### 代码

```python3
class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        sumt = sum(nums[:k])
        ans = sumt
        for i in range(k, len(nums)):
            sumt = sumt - nums[i-k] + nums[i]
            ans = max(ans, sumt)
        return ans/k
```