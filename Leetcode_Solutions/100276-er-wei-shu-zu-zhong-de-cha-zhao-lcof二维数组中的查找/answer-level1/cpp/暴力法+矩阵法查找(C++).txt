### 解题思路
暴力法1：遍历整个二维数组的每一个元素，判断目标值是否在二维数组中存在，即依次遍历二维数组的每一行和每一列。如果找到一个元素等于目标值，则返回true，否则返回false

矩阵方法2：从矩阵右上角开始，即int row = 0, col = matrix[0].size() - 1;以矩阵的右上角作为起点与target对比，若右上角值大于target，则列值减一,若右上角小于target，则行值加一，否则，返回true

矩阵方法3：矩阵左下角开始，即从矩阵左下角开始，即int row = matrix.size() - 1, col = 0;以矩阵的左下角作为起点与target对比，若左下角值大于target，则行值减一,若左下角小于target，则列值加一，否则，返回true
        


### 代码

```cpp
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int row = 0, col = matrix[0].size() - 1;//右上角开始
        while(row < matrix.size() && col >= 0)
        {
            if(matrix[row][col] > target)
                col--;
            else if(matrix[row][col] < target)
                row++;
            else
                return true;
        }
        return false;
    }
};
```