### 解题思路
可以列一次，行一次 2分法，但是代码看起来会很冗余
直接拿所有元素做2分法，比较简洁，注意坐标的计算就好了

### 代码

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      if(matrix.size() == 0 || matrix[0].size() == 0)  return false;
      if(target < matrix[0][0] || target > matrix[matrix.size() - 1][matrix[0].size() - 1])  return false;

      int m = matrix.size(), n = matrix[0].size();
      int left = 0, right = m * n - 1;

      while(left <= right){
        int mid = left + (right - left) / 2;
        if(matrix[mid / n][mid % n] == target)
          return true;
        else if(matrix[mid / n][mid % n] < target)
          left = mid + 1;
        else
          right = mid - 1;
      }

      return false;
    }
};
```