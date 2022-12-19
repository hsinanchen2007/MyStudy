### 解题思路
1、第一次二分查找最后一列，定位目标所在的行，即最后返回的行mid；若该数值小于目标，则在下一行mid + 1，或者不在矩阵范围。
2、第二次二分查找mid行，判断目标值是否存在。

### 代码

```cpp
class Solution {
public:
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(matrix.size() == 0 || matrix[0].size() == 0)
        return false;
    
    int col = matrix[0].size() - 1;
    int i = 0;
    int j = matrix.size() - 1;
    int mid = 0;
    while(i <= j){
        mid = i + (j - i) / 2;
        if(matrix[mid][col] == target)
            return true;
        if(matrix[mid][col] < target)
            i = mid + 1;
        else
            j = mid - 1;
    }

    //mid行的最后一个数值小于目标值，说明在下一行
    mid = matrix[mid][col] > target ? mid : mid + 1;
    if(mid >= matrix.size())
        return false;

    int m = 0;
    int n = col;
    while(m <= n){
        int midRow = m + (n - m) / 2;
        if(matrix[mid][midRow] == target)
            return true;
        if(matrix[mid][midRow] < target)
            m = midRow + 1;
        else
            n = midRow - 1;
    }
    
    return false;
}
};
```