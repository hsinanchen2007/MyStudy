### 解题思路
dp[i]记录以nums[i]作为最后一个元素的最长摆动序列状态
dp[i] = maxlen(dp[j])+nums[i:i+1]

循环内部判断条件 (dp[j][-1]-dp[j][-2])*(dp[j][-1]-nums[i])有溢出风险，
但是分开来写太长了,所幸最后通过了...

### 代码

```python
class Solution:
    # dp[i] = maxlen(dp[j])+nums[i:i+1]
    # dp[i]表示以nums[i]作为最后一个元素的最长摆动序列状态
    def wiggleMaxLength(self, nums: List[int]) -> int:
        t = len(nums)
        if t == 1:
            return t
        
        dp = [[x] for x in nums]
        # 记录最长摆动序列的长度
        max_len = 0
        # 计算缓存表dp[i]
        for i in range(1,t):
            # 找出dp[j]中最长摆动序列
            for j in range(i):
                if len(dp[j]) >= 2 and (dp[j][-1]-dp[j][-2])*(dp[j][-1]-nums[i]) > 0 and len(dp[j]) + 1 > len(dp[i]):
                    dp[i] = dp[j] + nums[i:i+1]
                elif len(dp[j]) == 1:
                    if nums[i] !=  nums[j]:
                        dp[i] = dp[j] + nums[i:i+1]
                    else:
                        dp[i] = [nums[i]]
            print(dp[i])
            if len(dp[i]) > max_len:
                max_len = len(dp[i])
        return max_len



```