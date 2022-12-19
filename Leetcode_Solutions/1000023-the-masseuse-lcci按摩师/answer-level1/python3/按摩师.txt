### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/8179cfa5252b0445bd20b2dbe37c83dd7fa36f095b258cce1697db1593af27a4-image.png)
1.自底向上。dp[i]表示从第i天开始的最长时间，等价于max（今天按+dp[i+2]，dp[i+1]）
2.自顶向下的递归写法
### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        # dp = [0]*(len(nums)+2)
        # for i in range(len(nums)-1, -1, -1):
        #     dp[i] = max(dp[i+1], dp[i+2]+nums[i])
        # return dp[0]

        # dp_i, dp_i1, dp_i2 = 0, 0, 0
        # for i in range(len(nums)-1, -1, -1):
        #     dp_i = max(dp_i1, dp_i2+nums[i])
        #     dp_i2 = dp_i1
        #     dp_i1 = dp_i
        # return dp_i
        
        meno = [-1]*len(nums)
        return self.dp(nums, meno, 0)

    def dp(self,nums, meno, start):
        if start>=len(nums):
            return 0
        if meno[start]!=-1:
            return meno[start]
        res = max(self.dp(nums, meno, start+1), self.dp(nums, meno, start+2)+nums[start])
        meno[start] = res
        return res



            
            
```