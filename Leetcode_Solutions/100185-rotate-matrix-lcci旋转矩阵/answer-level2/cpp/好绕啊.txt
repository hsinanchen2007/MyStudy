### 解题思路
每次处理一圈，由外圈向内圈
每个圈都做顺时针旋转90度操作。

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int> > tmp=matrix;
        for(int i=0;i<n/2;i++){
            for(int j=i;j<n-1-i;j++){
                //matrix[j][n-1-i]=tmp[i][j];
                swap(matrix[j][n-1-i],matrix[i][j]);
                swap(matrix[i][j],matrix[n-1-j][i]);
                swap(matrix[n-1-j][i],matrix[n-1-i][n-1-j]);
            }
        }
    }
};
```