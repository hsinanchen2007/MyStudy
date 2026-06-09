```c++
class Solution {
public:
    // https://zhuanlan.zhihu.com/p/32804477
    bool isMatch(string s, string p) {
        int i = s.size();
        int j = p.size();
        memo = vector<vector<int>>(i + 1, vector<int>(j + 1, -1));
        return isMatch(s, i, p, j) == 1;
    }

private:
    int isMatch(const string& text, int t, const string& pattern, int p) {
        if (memo[t][p] != -1) return memo[t][p];
        // empty string matches empty pattern
        if (!t && !p) return memo[t][p] = 1;
        // non-empty string does not match empty pattern
        if (!p) return memo[t][p] = 0;
        // empty string and non-empty pattern
        if (!t) {
            // pattern: ***
            for (int i = p - 1; i >= 0; i--) {
                if (pattern[i] != '*') return memo[t][p] = 0;
            }
            return memo[t][p] = 1;
        }

        switch (pattern[p - 1]) {
        case '?':
            // text: abc
            // pattern: ab?
            return memo[t][p] = isMatch(text, t - 1, pattern, p - 1);

        case '*':
            for (int i = t; i >= 0; i--) {
                if (isMatch(text, i, pattern, p - 1)) return memo[t][p] = 1;
            }
            return memo[t][p] = 0;

        default:
            // text: abcd
            // pattern: abc*d
            if (pattern[p - 1] == text[t - 1]) {
                return memo[t][p] = isMatch(text, t - 1, pattern, p - 1);
            }
            return memo[t][p] = 0;
        }
    }

    vector<vector<int>> memo;
};
```