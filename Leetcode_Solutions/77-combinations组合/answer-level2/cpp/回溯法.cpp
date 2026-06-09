```
class Solution {
    void backtrack(int n, int k, vector<int> &v, vector<vector<int> > &vs){
        if(v.size()==k){
            vs.push_back(v);
            return;
        }
        for(; n; --n){
            v.push_back(n);
            backtrack(n-1,k,v,vs);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        vector<vector<int> > vs;
        backtrack(n,k,v,vs);
        return vs;
    }
};
```
