```
class Solution {
    int flag = -INFINITY;
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size()==0) return res;
        if(matrix[0].size()==0) return res;
        int m = matrix.size(), n = matrix[0].size(), cnt = m * n;
        int idx = 0;
        int i = -1, j = -1;
        while(idx < cnt)
        {
            for(i++,j++; j < n && matrix[i][j] != flag; j++)
            {
                res.push_back(matrix[i][j]);
                matrix[i][j] = flag;
                idx++;
            }
            for(i++,j--; i < m && matrix[i][j] != flag; i++)
            {
                res.push_back(matrix[i][j]);
                matrix[i][j] = flag;
                idx++;
            }
            for(i--,j--; j >= 0 && matrix[i][j] != flag; j--)
            {
                res.push_back(matrix[i][j]);
                matrix[i][j] = flag;
                idx++;
            }
            for(i--,j++; i >= 0 && matrix[i][j] != flag; i--)
            {
                res.push_back(matrix[i][j]);
                matrix[i][j] = flag;
                idx++;
            }
        }
        return res;
    }
};
```
