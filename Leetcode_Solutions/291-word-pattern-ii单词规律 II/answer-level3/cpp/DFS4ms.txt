### 代码

```cpp
class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        int n = pattern.size();
        int m = str.size();
        unordered_map<char, int> dict;
        vector<string> memo;
        unordered_set<string> helper;
        function<bool(int, int)> dfs = [&](int ppos, int spos)->bool{
            //cout << ppos << ";" << spos << "***";
            if (ppos == n) {
                return spos == m;
            } else if (spos == m) {
                return false;
            }
            int ind = dict[pattern[ppos]];
            if (ind == ppos && ind == memo.size()) {
                int last = m - (n - ppos - 1);
                for (int i = 1; spos + i <= last; i++) {
                    string t = str.substr(spos, i);
                    if (helper.count(t)) {
                        continue;
                    }
                    helper.insert(t);
                    memo.push_back(t);
                    if (dfs(ppos + 1, spos + i)) {
                        return true;
                    }
                    helper.erase(t);
                    memo.pop_back();
                }
            } else if (ind < memo.size() && spos + memo[ind].size() <= m && memo[ind] == str.substr(spos, memo[ind].size())) {
                memo.push_back("");
                if (dfs(ppos + 1, spos + memo[ind].size())) {
                    return true;
                }
                memo.pop_back();
            }
            return false;
        };
        for (int i = 0; i < n; i++) {
            if (!dict.count(pattern[i])) {
                dict[pattern[i]] = i;
            }
        }
        return dfs(0, 0);
    }
};
auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
```