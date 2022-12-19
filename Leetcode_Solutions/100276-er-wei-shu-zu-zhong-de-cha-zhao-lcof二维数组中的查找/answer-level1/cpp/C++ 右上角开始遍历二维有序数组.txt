#### 复杂度分析
时间复杂度：O(N+M)
空间复杂度:O(1)


#### 代码
```
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(!matrix.size())
            return false;
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0,col = m - 1;
        while((row < n) && (col>=0)){
            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col]>target){
                col--;
            }
            else row++;
        }
        return false;
    }
};
```
