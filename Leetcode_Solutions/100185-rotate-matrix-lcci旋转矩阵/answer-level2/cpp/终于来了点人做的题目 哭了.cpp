### 解题思路
两次翻转

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size()-1; i++)
            for (int j = i+1; j < matrix.size(); j++)
                swap(matrix[i][j], matrix[j][i]);
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix.size()/2; j++)
                swap(matrix[i][j], matrix[i][matrix.size()-1-j]);
    }
};
```