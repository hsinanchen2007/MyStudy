```C++ []
class Solution {
public:
    bool backtrace(const string& p, unordered_map<char, int>& counts, const string& s, int i, int j, 
            unordered_map<char, string>& m, unordered_set<string>& used) {
        if (i == p.size()) return j == s.size();
        if (j >= s.size()) return false;
        if (m.count(p[i])) {
            if (s.substr(j, m[p[i]].size()) != m[p[i]]) return false;
            if (backtrace(p, counts, s, i + 1, j + m[p[i]].size(), m, used)) return true;
        } else {
            for (int k = 1; k <= (s.size() - j) / counts[p[i]]; ++k) {
                if (used.count(s.substr(j, k))) continue;
                m[p[i]] = s.substr(j, k);
                used.insert(s.substr(j, k));
                if (backtrace(p, counts, s, i + 1, j + k, m, used)) return true;
                used.erase(s.substr(j, k));
            }
            m.erase(p[i]);
        }
        return false;
    }
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char, int> counts;
        for (auto c : pattern) ++counts[c];
        unordered_map<char, string> m;
        unordered_set<string> used;
        return backtrace(pattern, counts, str, 0, 0, m, used);
    }
};
```

![image.png](https://pic.leetcode-cn.com/1bfe291e57eda5de5d793e2d6fc04272936824c9a7d5eee9b821bb58e8847624-image.png)
