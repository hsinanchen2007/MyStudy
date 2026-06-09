### 解题思路
每次循环处理4个元素。
循环次数为：
1. 如果元素行数为偶数，则为左上角的 n/2*n/2 矩阵，处理的所有元素个数为  `4*(n/2)*(n/2)=n^2` 个。
2. 如果元素行数为基数，则为左上角的 (n/2+1)*n/2 矩阵， 处理的所有元素个数为 `4*(n/2+1)*(n/2)+1=n^2`个

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int height = matrix.size();
        if (!height) return;
        int row = height % 2 ? height / 2 + 1 : height / 2;
        int col = height / 2;
        for (int i = 0; i < col; ++i) {
            for (int j = 0; j < row; ++j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[height - 1 - j][i];
                matrix[height - 1 - j][i] = matrix[height - 1 - i][height - 1 - j];
                matrix[height - 1 - i][height - 1 - j] = matrix[j][height - 1 - i];
                matrix[j][height - 1 - i] = tmp;
            }
        }
    }
};
```