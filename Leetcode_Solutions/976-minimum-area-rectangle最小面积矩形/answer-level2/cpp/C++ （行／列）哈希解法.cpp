```
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        map<int, set<int> > m;
        for (auto& p : points) {
            m[p[0]].insert(p[1]);
        }
        vector<int> rows;
        for (auto& p : m) rows.push_back(p.first);
        int res = INT_MAX;
        for (int i = 1; i < rows.size(); ++i) {
            auto& s1 = m[rows[i]];
            for (int j = 0; j < i; ++j) {
                auto& s2 = m[rows[j]];
                auto it1 = s1.begin();
                auto it2 = s2.begin();
                int dr = rows[i] - rows[j];
                int dc = INT_MAX;
                int prev = -1;
                while (it1 != s1.end() && it2 != s2.end()) {
                    if (*it1 == *it2) {
                        if (prev != -1) {
                            dc = min(dc, *it1 - prev);
                        }
                        prev = *it1;
                        ++it1;
                        ++it2;
                    } else if (*it1 < *it2) {
                        ++it1;
                    } else {
                        ++it2;
                    }
                }
                if (dc != INT_MAX) {
                    res = min(res, dr * dc);
                }
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/03795f1508d8022123d5d52a18751791f6ddad90e872961c720188783bdb4703-image.png)
