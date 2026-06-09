### 解题思路
刚开始想着一圈一圈旋转着转
然后，试了一下转置看看，结果发现，转置一下，再对称一下就可以实现矩阵的旋转。amazing~

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n<=1) return;
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }

        for(int i=0; i<n; ++i){
            for(int j=0; j<n/2; ++j){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i][n-j-1];
                matrix[i][n-j-1] = tmp;
            }
        }
    }
};
```