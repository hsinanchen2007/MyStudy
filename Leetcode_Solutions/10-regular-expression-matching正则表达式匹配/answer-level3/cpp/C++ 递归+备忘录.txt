```c++
class Solution {
public:
    // https://zhuanlan.zhihu.com/p/32793234
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
            // pattern: a*b*c*
            // pattern: a*b*xc*
            for (int i = p - 1; i >= 0; i--) {
                if (pattern[i] != '*') return memo[t][p] = 0;
                i--;
            }
            // pattern: *b*c*   (wrong pattern, * without a preceding element, not available in test cases)
            return memo[t][p] = (pattern[0] != '*');
        }

        char pre = 0;

        switch (pattern[p - 1]) {
        case '.':
            // text: abc
            // pattern: ab.
            return memo[t][p] = isMatch(text, t - 1, pattern, p - 1);

        case '*':
            // wrong pattern, * without a preceding element, not available in test cases
            if (p - 2 < 0) return memo[t][p] = 0;

            pre = pattern[p - 2];
            for (int i = 0; i <= t; i++) {
                if (isMatch(text, t - i, pattern, p - 2)) {
                    // text: abc
                    // pattern: abcd*
                    return memo[t][p] = 1;
                } else {
                    if (i == t) break;

                    // text: abce
                    // pattern: abcd*
                    // text: aaaaaaa
                    // pattern: a*, .*
                    if (!isMatch(pre, text[t - 1 - i])) return memo[t][p] = 0;
                }
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

    bool isMatch(char expect, char actual) {
        if (expect == '.') return true;
        return expect == actual;
    }

    vector<vector<int>> memo;
};
```