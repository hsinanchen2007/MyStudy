### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size()==0) return;
        int N=matrix.size();
        //对角
        for(int i=0; i<N; ++i){
            for(int j=i+1; j<N; ++j){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        //左右
        for(int i=0; i<N; ++i){
            for(int j=0; j<N/2; ++j){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i][N-1-j];
                matrix[i][N-1-j] = tmp;
            }
        }
    }
};
```