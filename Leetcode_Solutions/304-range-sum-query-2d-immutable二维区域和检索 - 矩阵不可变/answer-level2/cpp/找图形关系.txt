### 解题思路
此处撰写解题思路

### 代码

```cpp
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return ;
        sum = matrix;
        for(int i = 0 ; i < sum.size() ; ++i)
        {
            for(int j = 1 ; j < sum[0].size(); ++j)
            {
                sum[i][j] += sum[i][j - 1];
            }
        }
        for(int i = 0 ; i < sum[0].size() ; ++i)
        {
            for(int j = 1 ; j < sum.size(); ++j)
            {
                sum[j][i] += sum[j - 1][i];
            }
        }//求和
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 == 0 || col1 == 0)
        {
            if(row1 == 0 && col1 == 0)
                return sum[row2][col2];
            else if(row1 == 0)
                return sum[row2][col2]  - sum[row2][col1 - 1];
            else
                return sum[row2][col2]  - sum[row1 - 1][col2];
        }
        return sum[row2][col2] - sum[row1 - 1][col2] - sum[row2][col1 - 1] + sum[row1 - 1][col1 - 1];
    }
private:
    vector<vector<int>> sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
```