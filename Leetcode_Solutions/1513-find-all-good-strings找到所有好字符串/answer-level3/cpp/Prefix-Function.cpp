### 解题思路

- 使用一维数组`dp[m]`（m为evil的长度）保存当前匹配数为0到m-1的串的总数。
- 利用Prefix-Function，预先计算状态转移函数`f[i][j]`，表示当前匹配长度为i时，下一个字母为j的转移情况。
- 每增加一位，枚举26个字母进行状态转移。
- 如果当前的下限（s1）仍有效，需要扣除与s1前缀相同，但最后一个字母小于s1的贡献
- 如果当前的上限（s2）仍有效，需要扣除与s2前缀相同，但最后一个字母大于s2的贡献
- 如果s1在这一位匹配了evil，则之后s1失效，不再需要对s1进行额外扣除
- 如果s2在这一位匹配了evil，则之后s2失效，不再需要对s2进行额外扣除

大家的思路都差不多，具体实现的差别主要是如何加上s1和s2的约束。

这里强烈推荐下`cp-algorithms`上面的[Prefix-Function](https://cp-algorithms.com/string/prefix-function.html)这一节，个人觉得是目前讲解这一内容讲解得最透彻的。

### 代码

```cpp
typedef long long ll;
const ll MOD = 1e9 + 7;

class Solution {
public:
    int findGoodStrings(int n, string s1, string s2, string evil) {
        if (s1 > s2)
            return 0;
        int m = evil.size();
        vector<int> pi(m);
        string e = evil + "$";
        for (int i = 1; i < m; ++i) {
            int j = pi[i - 1];
            while (j != 0 && e[i] != e[j])
                j = pi[j - 1];
            pi[i] = e[i] == e[j] ? j + 1 : 0;
        }
        vector<vector<int>> f(m, vector<int>(26));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < 26; ++j) {
                int k = i;
                while (k != 0 && evil[k] - 'a' != j)
                    k = pi[k - 1];
                f[i][j] = evil[k] - 'a' == j ? k + 1 : 0;
            }
        vector<int> s(n + 1), t(n + 1);
        for (int i = 1; i <= n; ++i) {
            s[i] = f[s[i - 1]][s1[i - 1] - 'a'];
            if (s[i] == m)
                break;
        }
        for (int i = 1; i <= n; ++i) {
            t[i] = f[t[i - 1]][s2[i - 1] - 'a'];
            if (t[i] == m)
                break;
        }
        vector<ll> dp(m);
        dp[0] = 1;
        bool ua = false, ub = false;
        for (int i = 0; i < n; ++i) {
            vector<ll> ndp(m);
            for (int j = 0; j < m; ++j) {
                if (!dp[j])
                    continue;
                for (int k = 0; k < 26; ++k) {
                    int nxt = f[j][k];
                    if (nxt < m)
                        ndp[nxt] += dp[j];
                }
            }
            if (s[i] == m)
                ua = true;
            if (t[i] == m)
                ub = true;
            if (!ua) {
                for (int k = 0; k < s1[i] - 'a'; ++k) {
                    int nxt = f[s[i]][k];
                    if (nxt < m)
                        ndp[nxt]--;
                }
            }
            if (!ub) {
                for (int k = s2[i] - 'a' + 1; k < 26; ++k) {
                    int nxt = f[t[i]][k];
                    if (nxt < m)
                        ndp[nxt]--;
                }
            }
            for (int j = 0; j < m; ++j)
                dp[j] = (ndp[j] % MOD + MOD) % MOD;
        }
        ll ans = 0;
        for (ll i : dp)
            ans = (ans + i) % MOD;
        return ans;
    }
};
```