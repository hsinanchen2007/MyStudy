```
class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        if not nums:
            return 0
        res = []
        dp = [[1 for i in range(2)] for j in range(len(nums))]
        res.append(dp[0][0])
        res.append(dp[0][1])
        for i in range(1,len(nums)):
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i][1] = max(dp[i][1],dp[j][0]+1)
                elif nums[i] < nums[j]:
                    dp[i][0] = max(dp[i][0],dp[j][1]+1)
                else:               #若nums[i]=nums[j]，此时nums[i]不可能加在nums[j]后面
                    continue
            res.append(dp[i][0])
            res.append(dp[i][1])
        return max(res)

#dp[i][0]表示以nums[i]结尾且当前位置为降序的最长摆动序列，dp[i][1]表示以nums[i]结尾且当前位置为升序的最长摆动序列
```
