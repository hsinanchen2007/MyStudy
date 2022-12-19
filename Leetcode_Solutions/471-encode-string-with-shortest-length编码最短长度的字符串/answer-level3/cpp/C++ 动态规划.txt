```
class Solution {
public:
    int find_rep_sub_size(string s) {
        return (s + s).find(s, 1);
    }
    int num_len(int n) {
        return (n < 10) ? 1 : 1 + num_len(n / 10);
    }
    string encode(string s) {
        int N = s.size();
        vector<vector<string> > dp(N, vector<string>(N));
        for (int i = 0; i < N; ++i) 
            dp[i][i] += s[i];
        for(int len = 2; len <= N; ++len) {
            for (int i = 0; i + len <= N; ++i) {
                int j = i + len - 1;
                dp[i][j] = s.substr(i, len);
                int sub_size = find_rep_sub_size(s.substr(i, len));
                if (sub_size < len && (num_len(len / sub_size) + 2 + dp[i][i + sub_size - 1].size()) < dp[i][j].size())
                    dp[i][j] = (to_string(len / sub_size)) + "[" + dp[i][i + sub_size - 1] + "]";
                for (int k = i; k < j; ++k) {
                    if (dp[i][k].size() + dp[k + 1][j].size() < dp[i][j].size())
                        dp[i][j] = dp[i][k] + dp[k + 1][j];
                }
            }
        }
        return dp[0][N - 1];
    }
};
```
![image.png](https://pic.leetcode-cn.com/0a9b64d6fbfb2b7e2baf0b6ef781525c3852bd731f5852b809a6b0a05873e97a-image.png)
