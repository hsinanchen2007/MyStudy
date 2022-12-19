### 解题思路
第一次A动规的题，双百，留作纪念啦啦啦……

### 代码

```cpp
class Solution {
public:
    int massage(vector<int>& nums) {
        if(!nums.size())return 0;
        int dp[nums.size()][2];
        dp[0][0]=0,dp[0][1]=nums[0];
        for(int i=1;i<nums.size();i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=dp[i-1][0]+nums[i];
        }
        return max(dp[nums.size()-1][0],dp[nums.size()-1][1]);
    }
};
```