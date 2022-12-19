### 解题思路
🔨🔧 必胜 

### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        if not nums :
            return 0
        if len(nums)<3 :
            return max(nums)
        dp=[0]*len(nums)
        dp[0]=nums[0]
        dp[1]=nums[1]
        for i in range(2,len(nums)) :
            dp[i]=nums[i]+max(dp[:i-1])
        return max(dp)
```