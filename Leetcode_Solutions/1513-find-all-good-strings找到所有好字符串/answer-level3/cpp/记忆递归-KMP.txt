```
#define LL long long
const LL MOD = 1e9 + 7;

class Solution {
public:
    int next[50];
    LL dp[550][55][2][2];
    string low, high, evil;

    int dfs(int e_cur, int s_cur, int low_bound, int high_bound) {
        if (e_cur == evil.size()) return 0;

        if (s_cur == low.size()) return 1;

        if (dp[s_cur][e_cur][low_bound][high_bound] != -1) return dp[s_cur][e_cur][low_bound][high_bound];

        LL ans = 0;
        char st = 'a', ed = 'z';
        if (low_bound) {
            st = low[s_cur];
        }
        if (high_bound) {
            ed = high[s_cur];
        }
        for (char c = st; c <= ed; c++) {
            int k = e_cur;
            while (k != -1 && evil[k] != c) k = next[k];
            ans = (ans + dfs(k + 1, s_cur + 1, low_bound && c == st, high_bound && c == ed)) % MOD;
        }
        dp[s_cur][e_cur][low_bound][high_bound] = ans;
        return ans;
    }

    void build(string pattern) {
        int j;
        for (int i = 0, j = next[0] = -1; i < pattern.size(); next[++i] = ++j) {
            while (j != -1 && pattern[i] != pattern[j]) j = next[j];
        }
    }


    int findGoodStrings(int n, string s1, string s2, string evil) {
        build(evil);
        low = s1;
        high = s2;
        this->evil = evil;
        memset(dp, -1, sizeof(dp));
        return dfs(0, 0, 1, 1);

    }
};
```
