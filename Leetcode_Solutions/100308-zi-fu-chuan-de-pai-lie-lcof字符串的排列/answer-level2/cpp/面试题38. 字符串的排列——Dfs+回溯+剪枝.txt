```
class Solution {
private:
    void Dfs(vector<string>& res, string& s, size_t idx) {
        if(idx >= s.size()) {
            res.push_back(s);
            return;
        }
        for(size_t i = idx; i < s.size(); i++) {
            if(s.substr(idx, i - idx).find(s[i], 0) != s.npos) {
                continue;
            }
            swap(s[idx], s[i]);
            Dfs(res, s, idx + 1);
            swap(s[idx], s[i]);
        }
    }
public:
    vector<string> permutation(string s) {
        vector<string> res;
        Dfs(res, s, 0);
        return res;
    }
};
```
