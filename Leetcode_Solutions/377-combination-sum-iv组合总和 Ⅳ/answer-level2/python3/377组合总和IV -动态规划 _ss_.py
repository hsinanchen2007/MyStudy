### 解题思路
初始条件：dp[0]=1
行num：nums 列i：value(0-target)
转移方程：`dp[i]=dp[i]+dp[i-num]`
遍历每一行
### 代码

```python3
class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        from collections import defaultdict
        dp=defaultdict(int)#{key:0}
        dp[0]=1#初始化
        for i in range(1,target+1):#先对i遍历，保证i能够重复使用    
            for num in nums:
                dp[i]=dp[i]+dp[i-num]
        return dp[target]
```