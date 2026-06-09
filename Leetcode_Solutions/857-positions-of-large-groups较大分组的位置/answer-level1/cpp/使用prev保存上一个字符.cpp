我也不知道，我这方法好像挺蠢的，不过简单题不至于太高深的方法吧
```
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> res;
        char prev = 0;
        int cnt = 1;
        for (int i = 0; i < S.size(); ++i) {
            if (prev) {
                if (prev == S[i]) {
                    ++cnt;
                } else {
                    if (cnt >= 3) res.push_back({i - cnt, i - 1});
                    cnt = 1;
                }
            }
            if (prev && i == S.size() - 1) {
                if (cnt >= 3) res.push_back({i - cnt + 1, i});
            }
            prev = S[i];
        }
        return res;
    }
};
```
