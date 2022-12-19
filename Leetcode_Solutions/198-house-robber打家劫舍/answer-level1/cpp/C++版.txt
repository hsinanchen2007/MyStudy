### 解题思路
动态规划几个要素，这题关键是如何进行状态定义，官方题解为f(k)表示前k个房屋的收益，这个定义我觉得最好。

状态定义： f(k)表示前k个房屋的收益

状态转移方程： f(k) = max(f(k-1), f(k-2) +nums[k]) 表示前K个房屋的收益为前k-1个房屋和前k-2个房屋的较大者。因为不能偷相邻的。

初始状态，为了统一边界问题，加一个dp[0] = 0来统一处理dp[i-2]越界。dp[1] = nums[0]

### 代码

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        int* dp = new int[nums.size()+1];
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2; i < nums.size()+1; i++) {
            dp[i] = max(dp[i-2]+nums[i-1], dp[i-1]);
        }
        return dp[nums.size()];
    }
};
```