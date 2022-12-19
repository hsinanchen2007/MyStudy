```
class Solution {
    vector<vector<string>> res;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> m(n,1);
        vector<int> v;
        vector<string> t(n,string(n,'.'));
        solve(t,m,v,0,n);
        return res;
    }
    void solve(vector<string>& t, vector<bool>& m, vector<int>& v, int i,int& n){
        for(int j = 0; j < n; ++j){
            if(m[j]){
                int temp = 1;
                for(int k = 0; k < v.size();++k){
                    if(abs(v[k]-j) == i-k){
                        temp = 0;
                        break;
                    }
                }
                if(temp){
                    v.push_back(j);
                    m[j] = 0;
                    t[i][j] = 'Q';
                    if(i == n-1){
                        res.push_back(t);
                        m[j] = 1;
                        t[i][j] = '.';
                        v.pop_back();
                        break;
                    }
                    else{
                        solve(t,m,v,i+1,n);
                    }
                }
            }
        }
        if(i){
            t[i-1][v.back()] = '.';
            m[v.back()] = 1;
            v.pop_back();
        }
    }
};
```
