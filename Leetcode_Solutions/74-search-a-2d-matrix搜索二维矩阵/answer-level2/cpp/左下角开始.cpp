``` cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(matrix.empty()) return false;
        int x = matrix.size() - 1;
        if(matrix[x].empty()) return false;
        int y = 0;
        
        //注意溢出
        
        while (x >= 0 && y <= matrix[x].size() - 1) {
            if (target == matrix[x][y]) {
                return true;
            } else if (target > matrix[x][y]) {
                y++;
            } else if (target < matrix[x][y]) {
                if (y == 0) {
                    x --;
                    
                } else {
                    return false;
                }
            }
            
            
        }
        return false;
        
        
        
    }
};
```
