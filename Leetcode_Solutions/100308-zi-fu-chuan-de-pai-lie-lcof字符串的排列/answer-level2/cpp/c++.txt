```c++
class Solution {
public:
    
    void dfs(vector<int> &vis, set<string> &res, string s, string str) {
        
        if (str.size() == s.size()) {
            res.insert(str);
            return;
        }
        for (int i = 0; i < s.size(); i++) {
            if (i > 1 && s[i] == s[i-1] && vis[i-1] == 1) continue;
            if (vis[i] == 0) {
                vis[i] = 1;
                str += s[i];
                dfs(vis, res, s, str);
                vis[i] = 0;
                str.pop_back();
            }
        }
        return;
    }
    vector<string> permutation(string s) {
        if (s.size() == 0) {
            return {};
        }
        set<string> res;
        string str;
        vector<int> vis(s.size());
        dfs(vis, res, s, str);
        // sort(res.begin(), res.end());
        vector<string> res1;
        for (auto it = res.begin(); it != res.end(); it++) {
            // cout << *it << endl;
            res1.push_back(*it);
        }
        sort(res1.begin(), res1.end());
        return res1;
    }
};
```