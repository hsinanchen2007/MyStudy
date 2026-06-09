

### 代码

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())return false;       
        int row = matrix.size(), col = matrix[0].size();
        int l = 0, r = row*col - 1;
        while(l < r){
            int mid = l + r + 1>> 1;
            if(matrix[mid/col][mid%col] <= target)l = mid;
            else r = mid - 1;
        }
        return matrix[l/col][l%col] == target ? true : false;
    }
};
```