```
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) {
            return false;
        }
        if(matrix[0].size() == 0) {
            return false;
        }
        for(size_t i = 0; i < matrix.size(); i++) {
            if(matrix[i][0] <= target && matrix[i][matrix[i].size() - 1] >= target) {
                if(binary_search(matrix[i].begin(), matrix[i].end(), target)) {
                    return true;
                }
            }
        }
        return false;
    }
};
```
