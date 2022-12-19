### 解题思路
方法一：暴力法，直接遍历，过于简单。
方法二：从**右上角**

过程->
- 判断matrix是否为空
- 初始化行i=0, 列j=matrix.size()-1;
- 重复循环下列操作,for
   - matrix[i][j] == target, 直接返回
   - matrix[i][j] > target, i--;
   - matrix[i][j] < target, j++;

### 代码

```cpp
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        // 最关键的思路，从右上角开始
        if (matrix.empty()) return false;
        int i = 0, j = matrix[0].size() - 1;
        while (i >= 0 && i < matrix.size() && j >= 0 && j < matrix[0].size()) {
            if (matrix[i][j] == target)
                return true;
            else if(matrix[i][j] > target)
                j--;
            else if(matrix[i][j] < target)
                i++;
        }
        return false;
    }
};
```