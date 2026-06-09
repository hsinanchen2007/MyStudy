### 思路一：标记行列
分别保存值为0的行列，然后判断每行每列是否需要置0。

### 代码

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        set<int> st1;
        set<int> st2;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == 0) {
                    st1.insert(i);
                    st2.insert(j);
                }
            }
        }
        //判断每行
        for (int i = 0; i < row; ++i) {
            if (st1.count(i) > 0) {
                for (int j = 0; j < col; ++j) {
                    matrix[i][j] = 0;
                }
            }            
        }
        //判断每列
        for (int j = 0; j < col; ++j) {
            if (st2.count(j) > 0) {
                for (int i = 0; i < row; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
```

### 简化代码
```c++
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        set<int> st1;
        set<int> st2;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == 0) {
                    st1.insert(i);
                    st2.insert(j);
                }
            }
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (st1.count(i) > 0 || st2.count(j) > 0) {
                    matrix[i][j] = 0;
                }
            }    
        }
    }
};
```
