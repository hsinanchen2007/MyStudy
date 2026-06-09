### 解题思路
直观思路，先对矩阵转置，再对矩阵翻转

### 代码

```cpp
class Solution {
public:
    void transpose(vector<vector<int>> &matrix)  //转置
    {
        int n = matrix.size();
        for(int i=0;i<n;++i)
        {
            for(int j=i;j<n;++j)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        return;
    }
    void flip(vector<vector<int>> &matrix)  //翻转
    {
        //对矩阵每一行，前后对调
        int n = matrix.size();
        for(int i=0;i<n;++i)
        {
            vector<int> &row = matrix[i];  //取出第i行
            int lo=0,hi=n-1;
            while(lo<hi)
            {
                swap(row[lo++],row[hi--]);
            }
        }
        return;
    }
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size()==0)return;
        transpose(matrix);
        flip(matrix);
        return;
    }
};
```