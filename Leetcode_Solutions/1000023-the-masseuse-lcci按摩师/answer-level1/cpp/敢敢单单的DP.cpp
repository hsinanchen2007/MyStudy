### 解题思路


分析了一下题目：发现这不是 敢敢单单 的DP吗？

对于每一个位置，能构造转移到当前位置$\quad i的最大值dp_i \quad$的情况只有3种：

1. $dp_{i-1}$ 前$i-1$项最大值（不新增元素）
2. $dp_{i-2} + a[i]$ 前项$i-2$的最大值加上当前位置的权值 
3. $dp_{i-3} + a[i]$ 前项$i-3$的最大值加上当前位置的权值

构造出转移方程：
$$
dp[i]
\begin{cases}
dp[i] = dp[i-1]   \\
dp[i] = dp[i-2]+a[i]   \\
dp[i] = dp[i-3]+a[i]    
\end{cases}
$$
跑一便就可以出答案了。

考虑一下$n < 4$的情况要单独处理判断一下。



> 第一次时间、空间双100%。哈哈哈哈哈。DP大法好

### 代码

```cpp []
class Solution {
public:
    int dp[1005];
    int massage(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        if(n == 0)return ans;
        if(n == 1)return nums[0];
        if(n == 2)return max(nums[0],nums[1]);

        dp[0] = nums[0];
        ans = max(ans,dp[0]);
        dp[1] = nums[1]; 
        ans = max(ans,dp[1]);
        dp[2] = max(dp[0] + nums[2],dp[1]);
        ans = max(ans,dp[2]);

        for(int i = 3; i < n; i++){
            dp[i] = max(dp[i-1],max(dp[i-2] + nums[i],dp[i-3] + nums[i]));
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};
```
```python []
class Solution:
    def massage(self, nums: List[int]) -> int:
        dp = [0,0,0]
        ans = 0
        n = len(nums)
        if n == 0:
            return ans
        if n == 1:
            return nums[0]
        if n == 2:
            return max(nums[0],nums[1])
        dp[0] = nums[0]
        ans = max(ans,dp[0])
        dp[1] = nums[1];
        ans = max(ans,dp[1])
        dp[2] = max(dp[0] + nums[2],dp[1])
        ans = max(ans,dp[2])
        for i in range(3,n):
            dp.append(0)
            dp[i] = max(dp[i-1],max(dp[i-2] + nums[i],dp[i-3] + nums[i]))
            ans = max(ans,dp[i])
        return ans
```


