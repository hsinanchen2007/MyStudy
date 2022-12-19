保证组合数组元素升序，可以保证无重复。注意剪枝。
```
class Solution {
    void dfs(vector<int> &v, int k, int n, vector<vector<int> > &vs){
        for(int i=k==0?1:v[k-1]+1; i<=min(9, n); ++i){
            v[k] = i;
            if (i<n){
                if (k+1==v.size()) i=n-1;   // cut
                else dfs(v, k+1, n-i, vs);
            }
            else if (i==n && k+1==v.size()) vs.push_back(v);
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v(k, 0);
        vector<vector<int> > vs;
        dfs(v, 0, n, vs);
        return vs;
    }
};
```
