### 解题思路
关键点：理解状态移动方程
dp[i][0]表示考虑前i个预约，且第i个不接收预约的最长预约时间。
dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
dp[i][1]表示考虑前i个预约，且第i个接收预约的最长预约时间。犹豫相邻的不能同时预约，所以只能加上前面一个没预约的，即dp[i-1][0]。
dp[i][1] = nums[i-1] + dp[i - 1][0];

### 代码

```cpp
class Solution {
public:
    int massage(vector<int>& nums) {
        if(nums.size()<1) return 0;
        vector<vector<int>> dp(nums.size() + 1,vector<int>(2));
        //表示前面1个预约，并且第1个不接受预约的最长预约时间
        dp[1][0] = 0;
        //表示前面1个预约，并且第1不接受预约的最长预约时间
        dp[1][1] = nums[0];
        for (int i = 2; i < nums.size()+1; i++)
        {
            //dp[i][0]表示考虑前i个预约，且第i个不接收预约的最长预约时间
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            //dp[i][1]表示考虑前i个预约，且第i个接收预约的最长预约时间。犹豫相邻的不能同时预约，所以只能加上前面一个没预约的，即dp[i-1][0]。
            dp[i][1] = nums[i-1] + dp[i - 1][0];
        }
        return max(dp[nums.size()][0],dp[nums.size()][1]);
    }
};
```
执行结果：
    通过 显示详情
执行用时 :
    4 ms, 在所有 C++ 提交中击败了63.53%的用户
内存消耗 :
    8.2 MB, 在所有 C++ 提交中击败了100.00%的用户