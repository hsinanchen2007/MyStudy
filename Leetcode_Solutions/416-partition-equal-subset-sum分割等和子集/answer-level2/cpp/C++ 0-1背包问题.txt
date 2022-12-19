> 思路描述：首先能否分割，先求一下sum，如果sum是偶数的话，这道题就演变成是否可以从数组中找到几个数，使得其和等于sum/2，类似于背包问题，定义数组dp，dp\[i][j]表示从0...i中选出一些数字之和等于j，那么状态转移方程就等于
>
> dp\[i][j] = dp\[i-1][j] || dp\[i-1][j-nums[i]] || nums[i] - j

```C++
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i ++){
            sum += nums[i];
        }
        if(sum % 2 != 0) return false;
        vector<vector<bool>> dp(nums.size(), vector<bool>(sum/2 + 1, false));
        if(nums[0] == 0) dp[0][0] = true;
        for(int i = 1; i < nums.size(); i ++){
            for(int j = 0; j <= sum/2; j ++){
                if(nums[i] == j) dp[i][j] = true;
                else{
                    if(j >= nums[i])
                        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
                    else dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[nums.size() - 1][sum/2];
    }
};
```

> 优化一下时间复杂度

```C++
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i ++){
            sum += nums[i];
        }
        if(sum % 2 != 0) return false;
        vector<bool> dp(sum/2 + 1, false);
        for(int i = 0; i < nums.size(); i ++){
            if(nums[0] == i) dp[i] = true;
        }
        for(int i = 1; i < nums.size(); i ++){
            for(int j = sum/2; j >= 0; j --){
                if(nums[i] == j) dp[j] = true;
                else{
                    if(j >= nums[i])
                        dp[j] = dp[j] || dp[j - nums[i]];
                    else dp[j] = dp[j];
                }
            }
        }
        return dp[sum/2];
    }
};
```

