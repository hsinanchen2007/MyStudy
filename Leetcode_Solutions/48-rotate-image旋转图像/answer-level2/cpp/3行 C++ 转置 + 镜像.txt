```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i=0; i<matrix.size(); i++)
            for (int j=0; j<i; j++) swap(matrix[i][j], matrix[j][i]);
        
        for (auto& row: matrix) reverse(row.begin(), row.end());
    }
};
```
- 时间 O(N^2) 空间 O(1)
- 前俩行转置矩阵
- 最后一行做左右镜像
