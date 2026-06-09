### 解题思路
简单动态规划

### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        dp[0] = nums[0];
        int maximum = -9999;
        for(int i = 1;i < n;++i){
            dp[i] = max(dp[i - 1] + nums[i],nums[i]);
        }
        for(int i = 0;i < n;++i){
            if(maximum < dp[i]){
                maximum = dp[i];
            }
        }
    return maximum;
    }
};
```