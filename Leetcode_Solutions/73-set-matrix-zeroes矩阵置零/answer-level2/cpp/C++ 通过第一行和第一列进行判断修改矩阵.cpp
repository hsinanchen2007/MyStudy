### 解题思路
方式是看到lucifer大神的解答而改写出来的c++版本。

正常我们看到题目的第一想法是利用一个数组来存储每一行或者每一列是否全部为零，然后根据这个数组对```matrix```进行修改；这样的时间复杂度```O(m * n)```, 空间复杂度```O(m + n)```

而进阶要求我们使用**常数空间**，所以我们可以使用对第一行和第一列进行修改，然后根据第一行第一列来改变```matrix```

具体步骤为：
1. 首先要记录下第一行和第一列是否全部为零（就是第一行第一列内是否有零，最后再进行处理）
2. 遍历除第一行第一列以外的数据，如果有修改第一行第一列对应位置为零
3. 根据第一行第一列修改```matrix```
4. 修改第一行第一列

### 代码

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return;
        const int m = matrix.size();
        const int n = matrix[0].size();
        bool firstRow = false;
        bool firstCol = false;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                const int item = matrix[i][j];
                if (item == 0) {
                    if (i == 0) {
                        firstRow = true;
                    }
                    if (j == 0) {
                        firstCol = true;
                    }
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                const int item = matrix[i][j];
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        // 修改第一行和第一列
        if (firstRow) {
            for (int i = 0; i < n; i++) {
                matrix[0][i] = 0;
            }
        }

        if (firstCol) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
```