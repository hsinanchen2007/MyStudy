### 解题思路
此处撰写解题思路
矩阵坐标（i，j)的值，旋转90度之后，位置是(j, N-1-i);
偷个懒，直接创建一个临时的矩阵，变换完了之后赋值即可。
### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector <vector<int>> vec;
        for (int i = 0; i < matrix.size(); ++i)  
        {
            vector<int> row(matrix.size());
            vec.push_back(row);}
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[i].size(); ++j)
            {
                vec [j][matrix[i].size()-1-i] = matrix[i][j];
            }
        }
        matrix = vec;

    }
};
```