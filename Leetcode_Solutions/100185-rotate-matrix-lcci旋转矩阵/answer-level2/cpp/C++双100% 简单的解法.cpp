### 解题思路
无非就是创建一个新的 然后把原矩阵的第j列 输出成hang也就是输出成后面矩阵的行
例如：把原矩阵的第一列 逆序输出 变成后面矩阵的第一行

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //第i行是1 2 3 matrix[i][0] matrix[i][1] matrix[N]
        //第N列是 3 6 9 matrix[0][N] matrix[1][N]
        const int N=matrix.size();
        vector <vector<int>> matrixcopy;
        for(int i=0;i<=N-1;i++)
        {
            vector<int> hang;
            for(int j=N-1;j>=0;j--)
            {
                hang.push_back(matrix[j][i]);
            }
            matrixcopy.push_back(hang);
        }
        matrix=matrixcopy;


    }
};
```