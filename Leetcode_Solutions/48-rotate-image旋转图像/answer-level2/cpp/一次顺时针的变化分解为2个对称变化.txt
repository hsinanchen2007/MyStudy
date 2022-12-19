### 解题思路
这里顺时针旋转90度，可以认为是原矩阵沿左下到右上的对角线的一次对称变化加上一次横中心轴的对称变化。

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = (int)matrix.size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n-i;j++){
                swap(matrix[i][j],matrix[n-1-j][n-1-i]);
            }
        }
        for(int i = 0;i<n/2;i++){
            for(int j = 0;j<n;j++){
                swap(matrix[i][j],matrix[n-1-i][j]);
            }
        }
    }
};
```