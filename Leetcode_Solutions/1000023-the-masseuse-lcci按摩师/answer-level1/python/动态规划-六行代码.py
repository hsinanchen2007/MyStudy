### 解题思路
参考官方解答：
- 用dp0[i]表示当前位置i时不接愉悦,
故第i-1位置可能接受也可能不接受，dp0=max(dp0[i-1],dp1[i-1])；
- dp1[i]表示当前所处位置预约接受,所以显然dp1[i]=dp0[i-1]+nums[i]
   用两个参数dp0和dp1不断更新位置i的积累时间
- 转移方程
dp0=max(dp1,***dp0***)  注意更新时，转移方程右侧的变量会改变，所以需要tdp0保证更新正常
dp1=***dp0***+nums[i]
### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        dp0=dp1=0
        for i in range(len(nums)):
            tdp0=max(dp1,dp0)
            dp1=dp0+nums[i]
            dp0=tdp0
        return max(dp0,dp1)
```