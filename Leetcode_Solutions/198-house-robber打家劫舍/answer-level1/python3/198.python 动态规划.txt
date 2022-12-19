### 解题思路
根据题目要求，我们可以知道偷窃的房屋不能是相邻的，因此可以隔1，2,3....等等房屋偷窃。
因此首先**不能简单地理解为奇偶问题**。

**该题使用动态规划解题步骤：**

1.定义数据状态：即数据元素的含义，cur为当前房屋的到当前房屋为止窃取到的总金额，pre为到当前房屋的前一个房屋为止所窃取到的总金额

2.建立状态转移公式： (这里用数组来描述一下，容易理解,dp[i]表示新的cur,dp[i-1]表示pre,dp[i-2]表示上一个cur)  
  因此：dp[i] = max(dp[i-1],dp[i-2]+num)  ,num为当前房屋的金额

3.设定初值：这里我们可以仔细考虑下，因为我们要从起始房屋开始，但是要保证i-1,i-2不能导致越界。因此我们可以设cur = 0,pre = 0，
来方便从第一号房屋计算。

4.压缩空间：可以优化到空间复杂度已经为O(1)了。

5.选取结果：选取dp[-1]，即cur，即偷窃金额的最优值。


### 代码

```python
class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 每一个cur从开始到偷窃到i房屋的金额最优解，不能简单理解为奇偶问题！！！

        # 优化空间复杂度为O（1），时间复杂度O（n）
        cur,pre = 0,0
        for i in nums:
            cur,pre = max(pre+i,cur),cur
        return cur

        # 非优化空间复杂度O（n）,时间复杂度O（n）

        n = len(nums)
        dp = [0]*(n+2)
        for i in range(2,n+2):
            dp[i] = max(dp[i-1],dp[i-2]+nums[i-2])
        return dp[-1]
```