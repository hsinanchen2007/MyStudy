```C++ []
class Solution {
public:
    vector<vector<int> > memo;
    int dfs(const string& s, const string& p, int i, int j) {
        if (i == s.size()) return j == p.size() ? 1 : -1;
        if (j == p.size()) return i == s.size() ? 1 : -1;
        if (memo[i][j] != 0) return memo[i][j];
        if (j == p.size() - 1 || p[j + 1] != '*') {
            if (p[j] == '.' || p[j] == s[i]) {
                memo[i][j] = dfs(s, p, i + 1, j + 1);
                return memo[i][j];
            }
        } else {
            if (dfs(s, p, i, j + 2) > 0) {
                memo[i][j] = 1;
                return memo[i][j];
            }
            if (p[j] == '.' || p[j] == s[i]) {
                bool t = dfs(s, p, i + 1, j + 2) > 0 || dfs(s, p, i + 1, j) > 0;
                memo[i][j] = t ? 1 : -1;
                return memo[i][j];
            }
        }
        memo[i][j] = -1;
        return memo[i][j];
    }
    bool isMatch(string s, string p) {
        s += '#';
        p += '#';
        memo = vector<vector<int> >(s.size(), vector<int>(p.size(), 0));
        return dfs(s, p, 0, 0) > 0;
    }
};
```

![image.png](https://pic.leetcode-cn.com/2796f3c0d7325453a6ef1030ae7d31566ab2e863a4a6d2cd2cb50bbb1b5fadc2-image.png)
