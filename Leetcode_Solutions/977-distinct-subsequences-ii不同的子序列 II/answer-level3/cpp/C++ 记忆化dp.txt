# 解法一：
### 解题思路
记忆化DP
1，`dp[i][j]`代表从字符串`S`的第`i`位开始到结束有多少个子字符串以`'a' + j`结尾
2，状态转移方程为
如果`S[i] == 'a' + j`，则`dp[i][j] = dp[i + 1][j]`
否则，`dp[i][j] = 1 + sum{dp[i + i][k] | 0 <= k <= 25}`

这里为了简化逻辑，利用了记忆化dp进行处理

### 代码

```cpp
class Solution {
public:
    using ll = long long;
    const ll M = 1e9 + 7;
    string S;
    int N;
    
    ll MEMO[2000][26];
    
    ll dp(int i, int j) {
        if (MEMO[i][j] != -1) return MEMO[i][j];
        if (i == N - 1) return j == S[i] - 'a';
        ll res = 0;
        if (S[i] - 'a' == j) {
            res = 1;
            for (int k = 0; k < 26; ++k) {
                res += dp(i + 1, k);
            }
        } else {
            res = dp(i + 1, j);
        }
        res %= M;
        MEMO[i][j] = res;
        return res;
    }
    
    int distinctSubseqII(string S) {
        this->S = S;
        this->N = S.size();
        memset(MEMO, -1, sizeof(MEMO));
        
        ll res = 0;
        for (int i = 0; i < 26; ++i) {
            res += dp(0, i);
        }
        res %= M;
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/7fc82f0f2f6b4d63d5003505ec7473d5ab11a94f4ebdb3002a10d9aba5a78b43-image.png)

# 解法二：
非记忆化DP
思路同上

```cpp
class Solution1 {
public:
    using ll = long long;
    const ll M = 1e9 + 7;
    const int K = 26;
    
    int distinctSubseqII(string S) {
        int N = S.size();
        vector<vector<ll> > dp(N, vector<ll>(K, 0));
        dp[N - 1][S[N - 1] - 'a'] = 1;
        for (int i = N - 2; i >= 0; --i) {
            for (int j = 0; j < K; ++j) {
                if (S[i] - 'a' == j) {
                    for (int k = 0; k < 26; ++k) {
                        dp[i][j] += dp[i + 1][]
                    }
                    dp[i][j] += 1;
                } else {
                    dp[i][j] = dp[i + 1][j];
                }
                dp[i][j] %= M;
            }
        }
        ll res = 0;
        for (int i = 0; i < 26; ++i) {
            res += dp[0][i];
        }
        res %= M;
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/7d72579fa920318f64c5065faea38b26cb8ed9b51df2fcc2b2436508f997e82e-image.png)
