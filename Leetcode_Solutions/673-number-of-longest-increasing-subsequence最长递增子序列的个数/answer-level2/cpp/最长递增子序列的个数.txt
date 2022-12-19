### 解题思路
dp

### 代码

```cpp
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if ( n < 2) {
            return n;
        }
        vector<int> dp(n, 1);
        vector<int> count(n, 1);
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    } else if (dp[j]+1 == dp[i]) {
                        count[i] = count[i] + count[j];
                    }
                }
            }
        }
        int res = 0;
        int max_len = 0;
        for(int i = 0; i < n; ++i) {
            //cout<<dp[i]<<" "<<count[i]<<endl;
            if (dp[i] > max_len) {
                res = count[i];
                max_len = dp[i];
            } else if (dp[i] == max_len) {
                res = res + count[i];
            }
        }
        
        return res;
    }
};
```