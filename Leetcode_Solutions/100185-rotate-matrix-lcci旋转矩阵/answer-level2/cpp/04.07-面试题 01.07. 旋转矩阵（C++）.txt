### 解题思路
正向模拟

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        for (int i = 0; i < N / 2; i++) {
            for (int j = i; j < N - 1 - i; j++) {
                int cur = matrix[i][j];
                swap(cur,matrix[j][N-1-i]);
                swap(cur,matrix[N-1-i][N-1-j]);
                swap(cur,matrix[N-1-j][i]);
                swap(cur,matrix[i][j]);
             }
        }
    }
};
```