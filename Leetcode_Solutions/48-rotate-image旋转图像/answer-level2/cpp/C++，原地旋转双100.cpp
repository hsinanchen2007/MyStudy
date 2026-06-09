![图片.png](https://pic.leetcode-cn.com/403b0058a9a7526d670cc597506a1e847c0609f4fa18bbe46cd67538098744fc-%E5%9B%BE%E7%89%87.png)

### 解题思路
在旋转第一行时，用第一行的前n-1个位置逆序保存最后一列的n-1个数。此时第一行外的其他行（2~n行）的最后一个数已在逆转后相对应的列上（位置对应结果为逆序），而最后一列逆序保存着第一行的数。逆序最后一列。从第2行对n-1大小的矩阵重复上述操作至结束。


### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = matrix[0].size();
        int tmp;
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < column - i; ++j) {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[row - 1 - j][column - 1 - i];
                matrix[row - 1 - j][column - 1 - i] = tmp;
            }
            reverseColumn(matrix, column - 1 - i);
        }
    }
private:
    void reverseColumn(vector<vector<int>>& matrix, int column) {
        int row = matrix.size();
        int tmp = 0;
        for(int i = 0; i < row / 2; ++i) {
            tmp = matrix[i][column];
            matrix[i][column] = matrix[row - 1 - i][column];
            matrix[row - 1 - i][column] = tmp;
        }
    }
};
```

![TB2HtHIXVuWBuNjSszbXXcS7FXa_!!866276081.gif](https://pic.leetcode-cn.com/9d20555da9da0c69d3fddd505255cc56655f937aa0d14407db78347d426f6cd8-TB2HtHIXVuWBuNjSszbXXcS7FXa_!!866276081.gif)