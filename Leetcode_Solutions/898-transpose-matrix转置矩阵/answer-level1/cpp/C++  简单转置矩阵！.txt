### 解题思路
转置矩阵的列数 = 原矩阵的行数，这点一定要注意了！

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int R = A.size();
        int C = A[0].size();

        // 转置矩阵 T 为 C 行 R 列，原矩阵 A 为 R 行 C 列。
        vector<vector<int>> T(C, vector<int>(R, -1));

        // 挨个遍历赋值
        for (int r = 0; r < R; r++) 
            for (int c = 0; c < C; c++)
                T[c][r] = A[r][c];

        return T;
    }
};
```