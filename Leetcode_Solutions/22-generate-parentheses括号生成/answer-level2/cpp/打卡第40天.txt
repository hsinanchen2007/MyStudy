```
学习backtracking
```
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
    
        dfs(res, "", n, 0, 0);
        return res;
    }
    void dfs(vector<string>& res, string path, int n, int lc, int rc) {
        if (rc > lc || lc > n || rc > n) return;
        if (lc == rc && lc == n) {
            res.push_back(path);
            return;
        }
        dfs(res, path + '(', n, lc + 1, rc);
        dfs(res, path + ')', n, lc, rc + 1);
    }
        
    
};