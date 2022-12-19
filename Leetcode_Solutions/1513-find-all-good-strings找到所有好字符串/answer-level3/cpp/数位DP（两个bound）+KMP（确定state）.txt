```
const int MOD = 1e9+7;
typedef long long ll;
class Solution {
private:
    string small;
    string large;
    string evil;

public:
    void get_next(string& s, vector<int>& next) {
        int n = s.size(), k = -1, j = 0;
        while (j <= n - 1) {
            if (k == -1 || s[j] == s[k]) {
                ++k; ++j;
                next[j] = k;
            } else {
                k = next[k];
            }
        }
    }
    int findGoodStrings(int n, string s1, string s2, string evil) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = evil.size();
        large = s2;
        small = s1;
        this->evil = evil;
        vector<int> next(n3+1, -1);
        get_next(evil, next);
        vector<vector<int>> dp(n1+1, vector<int>(n3+1, -1));
        return dfs(0, 0, 1, 1, next, dp);
    }
    int dfs(int cur, int state, int flag1, int flag2, vector<int>& next, vector<vector<int>>& dp) {
        //bad state;
        if (state == evil.size()) {
            return 0;
        }

        if (cur == small.size()) {
            return 1;
        }
        if (!flag1 && !flag2 && dp[cur][state] != -1) {
            return dp[cur][state];
        }
        char end = flag2?large[cur]:'z';
        char start = flag1?small[cur]:'a';
        ll ret = 0;
        for (char i = start; i <= end; i++) {
            int new_state = state;
            while(new_state != -1 && evil[new_state] != i) {
                new_state = next[new_state];
            }
            ret = (ret + dfs(cur+1, new_state+1, flag1 && i == start,  flag2 && i == end, next, dp)) % MOD;
        }
        if (!flag1 && !flag2) {
            return dp[cur][state] = ret;
        }
        return ret;
    }
};
```
