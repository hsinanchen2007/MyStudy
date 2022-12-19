```
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (!matrix.size())
            return {};
        vector<int> res;
        int row = 0, colum = 0;
        int m = matrix.size(), n = matrix[0].size();
        while (true) {
            for (int j=colum;j<n;j++) {
                res.push_back(matrix[row][j]);
            }
            row++;
            if (row >= m)
                break;
            for (int i=row;i<m;i++) {
                res.push_back(matrix[i][n-1]);
            }
            n--;
            if (colum >= n)
                break;
            for (int j=n-1;j>=colum;j--) {
                res.push_back(matrix[m-1][j]);
            }
            m--;
            if (row >= m)
                break;
            for (int i=m-1;i>=row;i--) {
                res.push_back(matrix[i][colum]);
            }
            colum++;
            if (colum >= n)
                break;      
        }
        return res;
    }
};
```
