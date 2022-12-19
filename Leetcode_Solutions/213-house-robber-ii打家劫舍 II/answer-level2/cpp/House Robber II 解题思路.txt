### 解题思路
此问题是House Robber I 的升级版
如果是环形那么当抢劫第一家的时候最后一家不能抢，如果抢劫最后一家的时候第一家不能抢
可以化成两个问题
1. 抢劫1 ~ n-1 家（抢第一家，不抢最后一家
2. 抢劫2 ~ n 家（抢最后一家，不抢第一家

取最大情况

### 代码

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {

        int len = nums.size();

        if(len == 0) return 0;
        if(len == 1) return nums[0];
        if(len == 2) return max(nums[0], nums[1]);

        return max(rob1(nums, len), rob2(nums, len));
        
    }
    int rob1(vector<int>& nums, int len) {
        int dp[len + 1] = {0};

        
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < len - 1; ++i){
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        
        return dp[len - 2];
    }
    int rob2(vector<int>& nums, int len) {
        int dp[len + 1] = {0};

        dp[1] = nums[1];
        dp[2] = max(nums[1], nums[2]);
        
        for (int i = 3; i < len; ++i){
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        
        return dp[len - 1];
    }
};


```