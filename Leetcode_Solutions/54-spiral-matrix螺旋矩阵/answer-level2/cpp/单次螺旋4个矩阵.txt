```
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        if(matrix.size()==0 || matrix[0].size()==0) return {};
        int row=matrix.size(), col=matrix[0].size();
        vector<int> v(row*col,0);
        for(int l=0, r=col-1, t=0, b=row-1, c=0; l<=r && t<=b; ++l, --r, ++t, --b){
            for(int i=l; i<=r; v[c++]=matrix[t][i++]);
            for(int i=t+1; i<b; v[c++]=matrix[i++][r]);
            for(int i=r; i>=l && t<b; v[c++]=matrix[b][i--]);
            for(int i=b-1; i>t && l<r; v[c++]=matrix[i--][l]);
        }
        return v;
    }
};
```
