构建NxM的数组，遍历MxN矩阵

``` C++
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        if(A.empty())
            return A;
        int rows=A.size(),cols=A[0].size();
        vector<int> temp(rows,0);
        vector<vector<int>> res(cols,temp);
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++)
                res[j][i]=A[i][j];
        return res;
    }
};
```