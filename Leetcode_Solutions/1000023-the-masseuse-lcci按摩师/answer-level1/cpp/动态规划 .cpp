### 解题思路
典型的动态规划问题。用dp[i]表示截止到低i个客户所能服务的最长时间。当前时刻的最大时常之和上一时刻或者上上时刻有关。
```
    dp[i] = max(dp[i-1], dp[i-2]+nums[i])
```
表示如果当前时刻不服务那么总服务时长和上一时刻相同，如果服务则是上上时刻的最多时长加上当前时长

### 代码

```cpp
class Solution {
public:
    int massage(vector<int>& nums) {
        if(nums.empty()) return 0;
        int len = nums.size();
        vector<int> dp(len, 0);
        if(len==1) return nums[0];
        if(len==2) return std::max(nums[0], nums[1]);
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);
        for(int i=2; i<len; ++i){
            dp[i]=std::max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[len-1];
    }
};
```