```
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int i,j,k,n;
        for(j=cols-1; j>=1-rows; j--)
        {
            i = j>=0 ? 0 : -j;
            k = j>=0 ? j : 0;
            for(n=matrix[i++][k++]; i<rows && k<cols ; i++,k++)
            {
                if(matrix[i][k] != n)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
```
