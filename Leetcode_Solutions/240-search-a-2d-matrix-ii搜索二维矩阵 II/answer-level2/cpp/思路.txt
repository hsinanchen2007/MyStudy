### 解题思路
看了题解才想到，左下角出发就很简单
不然我应该只能想到每一行做2分查找的操作

### 代码

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      if(matrix.size() == 0 || matrix[0].size() == 0) return false;

      int col = matrix.size() - 1, row = 0;
      while(col >= 0 && row < matrix[0].size()){
        if(matrix[col][row] == target)
          return true;
        else if(matrix[col][row] > target)
          col--;
        else if(matrix[col][row] < target)
          row++;
      }

      return false;
    }
};
```