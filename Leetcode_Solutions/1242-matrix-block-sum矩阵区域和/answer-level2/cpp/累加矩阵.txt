### 解题思路
（看了别人的题解之后，我才反应过来这是一个卷积的操作，惭愧。）

我这里的主要思路就是建立一个累加矩阵，比如addNet[1][1] = mat[0][0] + mat[0][1] + mat[1][0] + mat[1][1]，然后根据情况进行计算就好了，其实我这个写的很粗糙来着，不过既然过了就不优化了。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m = mat.size(),n = mat[0].size();
        vector<vector<int> > addMat(m,vector<int>(n,0));
        vector<vector<int> > result(m,vector<int>(n,0));
        addMat[0][0] = mat[0][0];
        for(int i = 1;i < n;i++)
            addMat[0][i] = addMat[0][i-1] + mat[0][i];
        for(int i = 1;i < m;i++)
            addMat[i][0] = addMat[i-1][0] + mat[i][0];
        for(int i = 1;i < m;i++){
            for(int j = 1;j < n;j++){
                addMat[i][j] = addMat[i-1][j] + addMat[i][j-1] + mat[i][j] - addMat[i-1][j-1];
            }
        }
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                int a = i - K - 1,b = i + K,c = j - K - 1,d = j + K;
                if(b >= m)
                    b = m - 1;
                if(d >= n)
                    d = n - 1;
                if(a < 0 && c < 0)
                    result[i][j] = addMat[b][d];
                else if(c < 0)
                    result[i][j] = addMat[b][d] - addMat[a][d];
                else if(a < 0)
                    result[i][j] = addMat[b][d] - addMat[b][c];
                else
                    result[i][j] = addMat[b][d] - addMat[a][d] - addMat[b][c] + addMat[a][c]; 
            }
        }
        return result;
    }
};
```