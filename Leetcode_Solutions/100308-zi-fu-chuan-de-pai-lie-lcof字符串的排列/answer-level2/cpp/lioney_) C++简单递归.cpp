```
class Solution {
public:
    vector<string> permutation(string s) {
        set<string> res;
        dfs(s, 0, res);
        return vector<string>(res.begin(), res.end());
    }
    void dfs(string s, int level, set<string>& res) {
        if(level == s.size()) {
            res.insert(s);
            return;
        }
        for(int i=level; i<s.size(); i++) {
            swap(s[i], s[level]);
            dfs(s, level+1, res);
            swap(s[i], s[level]);
        }
    }
};
```
