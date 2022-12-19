### 解题思路
比如：
  1 2 3 4
5 1 2 3

前一行的前 3 个元素等于下一行的后 3 个元素，遍历所有行列，以此类推，出现不相同的情况，则返回 Flase
### 代码

```cpp
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        // 1 2 3 4   ->     1 2 3 4
        // 5 1 2 3   ->   5 1 2 3
        // 9 5 1 2   -> 9 5 1 2
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                // 这里 i,j 必须大于 0，因为后面需要比较上一行前一列的元素 i - 1, j - 1
                if (i > 0 && j > 0 && matrix[i][j] != matrix[i - 1][j - 1])
                    return false;
            }
        }

        return true;
    }
};
```