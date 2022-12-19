### 解题思路
dp 先画图，再写公式，再写代码。

![Screenshot from 2020-02-29 16-59-49.png](https://pic.leetcode-cn.com/86b616d89bf9e8941630c2226e7390a8d85f734df6421c05b42020264f8165b9-Screenshot%20from%202020-02-29%2016-59-49.png)

### 代码

```cpp
// 二维DP
int numDistinct(string s, string t) {
    int s_size = s.size(), t_size = t.size();
    vector<vector<long>> dp(t_size + 1, vector<long>(s_size + 1, 0));
    fill(dp[0].begin(), dp[0].end(), 1);
    for (int i = 0; i < t_size; ++i) {
        for (int j = 0; j < s_size; ++j) {
            if (t[i] == s[j]) dp[i+1][j+1] = dp[i+1][j] + dp[i][j];
            else dp[i+1][j+1] = dp[i+1][j]; 
        }
    }
    return dp[t_size][s_size];
}

// 一维DP
int numDistinct(string s, string t) {
    int s_size = s.size(), t_size = t.size();
    vector<long> dp(s_size + 1, 1);
    for (auto c : t) {
        auto last = dp[0]; // 记录上一个值
        dp[0] = 0;
        for (int j = 0; j < s_size; ++j) {
            auto record = dp[j+1];
            if (s[j] == c) dp[j+1] = last + dp[j];
            else dp[j+1] = dp[j];
            last = record;
        }
    }
    return dp.back();
}

```