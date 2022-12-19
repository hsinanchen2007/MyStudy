### 解题思路
dp

### 代码

```cpp
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(3, 0));
        int res = 0;
        int max_res = 0;
        dp[0][1] = INT_MIN;
        dp[0][2] = INT_MIN;
        for(int i = 0; i < n; ++i) {
            res = nums[i];
            if (res % 3 == 1) {
                dp[i+1][0] = max(dp[i][0], dp[i][2] + res);
                dp[i+1][1] = max(dp[i][1], dp[i][0] + res);
                dp[i+1][2] = max(dp[i][2], dp[i][1] + res);
            } else if (res % 3 == 2) {
                dp[i+1][0] = max(dp[i][0], dp[i][1] + res);
                dp[i+1][1] = max(dp[i][1], dp[i][2] + res);
                dp[i+1][2] = max(dp[i][2], dp[i][0] + res);
            } else {
                dp[i+1][0] = max(dp[i][0], dp[i][0] + res);
                dp[i+1][1] = max(dp[i][1], dp[i][1] + res);
                dp[i+1][2] = max(dp[i][2], dp[i][2] + res);
            }
            //cout<<dp[i+1][0]<<" "<<dp[i+1][1]<<" "<<dp[i+1][2]<<endl;
        }
        return dp[n][0];
    }

    void DFS(int& res, vector<int>& nums, int index, int current) {
        if (current % 3 == 0) {
            if (current > res) {
                res = current;
            }
        }
        if (index == nums.size()-1) {
            return;
        }
        for(int i = index+1; i < nums.size(); ++i) {
            DFS(res, nums, i, current+nums[i]);
        }
        return;
    }
};
```