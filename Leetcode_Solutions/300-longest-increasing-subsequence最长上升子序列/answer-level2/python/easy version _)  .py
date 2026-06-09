### 解题思路
将count次数存储到新建数组中，当走到当前数值时，用此数与其前面所有数进行比较，之后在更新数组的count个数，最后返回数组中最大的那个值。：）

### 代码

```python3
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums:
            return 0
        dp = []
        for i in range(len(nums)):
            dp.append(1)
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)
        return max(dp)


            
        
```