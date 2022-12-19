### 解题思路
dp[i] 表示是否能从 第i个位置 跳到最后一个位置。

状态转移：
min_step = 1 if dp[i] == True else min_step += 1
dp[i-1] = True if dp[i-1] >= min_step else False

结果：
dp[0]
### 代码

```python3
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        if n <= 1: return True
        min_step = 1
        for i in range(n-2,-1,-1):
            if nums[i] >= min_step:
                min_step = 1
            else:
                min_step +=1
        return nums[0] >= min_step
```