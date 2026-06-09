
```
class Solution {
    string s;
    string p;
    vector<vector<int>> f;
    bool dfs(int sidx, int pidx)
    {
        if(f[sidx][pidx] != -1)
            return f[sidx][pidx];
        
        if(pidx == p.size())
            return f[sidx][pidx] = sidx == s.size();

        bool res1 = (sidx < s.size() && pidx < p.size() && (s[sidx] == p[pidx] || p[pidx] == '.'));
        bool res2;
        if(pidx + 1 < p.size() && p[pidx + 1] == '*')
        {
            bool a = dfs(sidx, pidx + 2);
            bool b = res1 && dfs(sidx + 1, pidx);
            res2 = a || b ;
        }
        else
        {
            res2 = res1 && dfs(sidx + 1, pidx + 1);
        }
        return f[sidx][pidx] = res2;
    }
public:
    bool isMatch(string _s, string _p) {
        s = _s;
        p = _p;
        if(!s.size() && !p.size()) return true;//都没有可以
        f = vector<vector<int>>(s.size() + 1, vector<int>(p.size() + 1, -1));
        return dfs(0, 0);
    }
};
```
