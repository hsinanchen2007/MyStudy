```
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > vs(n,vector<int>(n));
        for(int v=1, l=0, r=n-1, t=0, b=n-1; v<=n*n; ++l, --r, ++t, --b){
            for(int i=l; i<=r && v<=n*n; vs[t][i++]=v++);
            for(int i=t+1; i<b && v<=n*n; vs[i++][r]=v++);
            for(int i=r; i>=l && v<=n*n; vs[b][i--]=v++);
            for(int i=b-1; i>t && v<=n*n; vs[i--][l]=v++);
        }
        return vs;
    }
};
```
