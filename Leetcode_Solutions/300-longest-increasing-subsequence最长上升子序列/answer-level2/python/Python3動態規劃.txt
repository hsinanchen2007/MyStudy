### 解题思路
dp動態規劃的思路,就是當前問題可以由重復子問題進行定義..
比如說要找最長上升子序列
            則最長上升子序列=第二長的序列+1,或者就是1
用dp存儲所有的最長上升子序列的長度
起始[1,1]
依次填寫dp表
[10,9,2,5,3,7,101,18]
  1 1 1 1 1 1  1   1
        2 2 2  222 222
            3  33  33
               4   4
### 代码 

```python3
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums:
            return 0
        dp = [1]
        for i in range(1,len(nums)):
            dp.append(1)
            for j in range(i):
                if nums[j] <nums[i]:
                    dp[i] = max(dp[i],dp[j]+1)
        return max(dp)
        
```