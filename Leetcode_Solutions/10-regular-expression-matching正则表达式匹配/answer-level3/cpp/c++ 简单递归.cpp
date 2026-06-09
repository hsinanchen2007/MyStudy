
```
class Solution {
public:
    vector<vector<int>> memory;
    int func(const string& s, int i, const string& p, int j) {
        int& res = memory[i][j];
        if (res != -1)
            return res;
        if (i == s.size() && j == p.size()) {
            res = 1;
            return res;
        }
        if (j < p.size() && p[j + 1] == '*') {
            if (i == s.size()) {
                res = func(s, i, p, j + 2);
            } else if ((s[i] == p[j] || p[j] == '.') && (func(s, i + 1, p, j) || func(s, i + 1, p, j + 2))) {
                res = 1;
            } else {
                res = func(s, i, p, j + 2);
            }
            return res;
        } else if (i < s.size() && (s[i] == p[j] || p[j] == '.')) {
            res = func(s, i + 1, p, j + 1);
            return res;
        }
        res = 0;
        return res;
    }
    bool isMatch(string s, string p) {
        memory.resize(s.size() + 1);
        for (int i = 0; i <= s.size(); ++i) {
            memory[i] = vector<int>(p.size() + 1, -1);
        }
        return func(s, 0, p, 0) > 0;
    }
};
```
![image.png](https://pic.leetcode-cn.com/7c38755be38eaeb4459050f847e982fc9bb4bd5ce1b18e32498578a0ea8884ff-image.png)
