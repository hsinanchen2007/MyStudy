```
class Solution {
public: 
    vector<string> ret;
    vector<string> generateParenthesis(int n) {
    if(n<=0) return ret;
    dfs(n,"",0,0);
    return ret;
    }
    void dfs(int n,string p,int l,int r)
    {
        if(l+r==n*2)
        {
            ret.push_back(p);
            return;
        }
        if(l<n)
            dfs(n,p+'(',l+1,r);
        if(r<l)
            dfs(n,p+')',l,r+1);
        
    }
};
```
