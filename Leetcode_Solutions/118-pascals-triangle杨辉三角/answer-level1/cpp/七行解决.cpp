规律：vs[row][col]=vs[row-1][col-1]+vs[row-1][col];注意边界。
```
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > vs;
        for(int row=0; row<numRows; ++row){
            vector<int> v(row+1,1);
            for(int i=0; ++i<row; v[i]=vs[row-1][i-1]+vs[row-1][i]);
            vs.push_back(v);
        }
        return vs;
    }
};
```
