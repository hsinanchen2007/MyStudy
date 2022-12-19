### 解题思路
1，先进行字符串分割
2，寻找所有可能的组合

### 代码

```cpp
class Solution {
public:
    vector<pair<string, string> > split(const string& s) {
        if (s.size() < 2) return {};
        vector<pair<string, string> > res;
        int N = s.size();
        for (int i = 0; i < N - 1; ++i) {
            if ((s[0] != '0' || s[i] != '0' || i == 0) && 
                    (s[i + 1] != '0' || s[N - 1] != '0' || i == N - 2)) {
                res.push_back({s.substr(0, i + 1), s.substr(i + 1)});
            }
        }
        return res;
    }
    vector<string> addPoint(const string& s) {
        if (s.size() == 1 || s.back() == '0') return {s};
        if (s[0] == '0') return {"0." + s.substr(1)};
        vector<string> res{s};
        for (int i = 1; i < s.size(); ++i) {
            res.push_back(s.substr(0, i) + "." + s.substr(i));
        }
        return res;
    }
    vector<string> ambiguousCoordinates(string S) {
        if (S.empty()) return {};
        string s = S.substr(1, S.size() - 2);
        vector<string> res;
        for (auto& p : split(s)) {
            for (auto& x : addPoint(p.first)) {
                for (auto& y : addPoint(p.second)) {
                    res.push_back("(" + x + ", " + y + ")");
                }
            }
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/55349ee5df9f5fb0139c098c10d7076511166f0dd67cfa00b56c09e9e55e8353-image.png)
