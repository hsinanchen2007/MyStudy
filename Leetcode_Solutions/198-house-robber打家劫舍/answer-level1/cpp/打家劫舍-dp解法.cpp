### 解题思路
动态规划。dp[i]表示偷窃前i个房间能获得的最大利益，那么它可以由之前的两种状态来得到：
    - 偷了第i - 2个房间，那么当前最大利益为dp[i - 2] + nums[i]；
    - 偷了第i - 1个房间，那么当前最大利益继承dp[i - 1]；
状态转移方程：dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
边界：dp[0] = nums[0]; dp[1] = max(nums[0], nums[1]);

### 代码

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)    return 0;
        int dp[len];
        for(int i = 0; i < len; i++){
            if(i == 0)  dp[i] = nums[i];   //边界
            else if(i == 1) dp[i] = max(nums[0], nums[1]);  //边界
            else          dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);      //状态转移方程
        }
        return dp[len - 1];
    }
};
```