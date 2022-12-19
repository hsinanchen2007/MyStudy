### 解题思路

将envelopes 按长排序，后面的问题就是求最长递增子序列。

### 代码

```cpp
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), CompareVector);
        int n = envelopes.size();
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        }

        vector<int> dp(n+1, 1);
        dp[0] = 0;

        int max_count = 0;
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
                    dp[i+1] = max(dp[i+1], 1+dp[j+1]);
                }
                max_count = max(max_count, dp[i+1]);
            }
        }

    
        return max_count;
    }

    static bool CompareVector(const vector<int>& vec1, const vector<int>& vec2) {
        return vec1[0] < vec2[0];
    }
};
```