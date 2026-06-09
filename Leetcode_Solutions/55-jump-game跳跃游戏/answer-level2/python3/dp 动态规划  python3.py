### 解题思路
dp[i]表示 包括i的一次跳跃路径中最远能到达的下标。
递推 dp[i] = max(nums[i] + i, dp[i-1])
如[2,3,1,1,4]中，dp[0]=2, dp[1]为从1开始最远为1+3=4，上一次最远为dp[1-1]=2, ->dp[1]=4

可优化空间 dp数组->dp变量

### 代码

```python3
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        '''
        # 贪心算法
        lastpos = len(nums) - 1
        for i in range(len(nums) - 2, -1, -1):
            if i + nums[i] >= lastpos:
                lastpos = i

        return lastpos == 0
        '''
        
        # dp[i]表示 包括i的一次跳跃路径中最远能到达的下标。
        # 递推 dp[i] = max(nums[i] + i, dp[i-1])
        # 如[2,3,1,1,4]中，dp[0]=2, dp[1]为从1开始最远为1+3=4，上一次最远为dp[1-1]=2, ->dp[1]=4
        dp = [0] * len(nums)
        for i in range(len(nums)):
            dp[i] = max(nums[i] + i, dp[i-1])
            if dp[i] >= len(nums) - 1:
                return True
            if dp[i] == i:
                return False

        # 可优化空间 dp数组->dp变量
        dp = 0
        for i in range(len(nums)):
            dp = max(nums[i] + i, dp)
            if dp >= len(nums) - 1:
                return True
            if dp == i:
                return False
```