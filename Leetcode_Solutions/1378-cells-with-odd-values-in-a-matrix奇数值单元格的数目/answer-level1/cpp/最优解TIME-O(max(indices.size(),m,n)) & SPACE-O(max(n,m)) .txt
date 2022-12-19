```
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<int> r(n,0);
        vector<int> c(m,0);
        for(int i = 0; i < indices.size(); i++)
        {
            r[indices[i][0]] = 1-r[indices[i][0]];
            c[indices[i][1]] = 1-c[indices[i][1]];
        }
        int sum_r = accumulate(r.begin(),r.end(),0);
        int sum_c = accumulate(c.begin(),c.end(),0);
        
        return (sum_r*m+sum_c*n-2*sum_r*sum_c);
    }
};
```
