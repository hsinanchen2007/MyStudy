```c++
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> res;
        
        /*calc col*/
        for(int i = 0; i < col; ++i){
            int maxRow = 0;
            bool isLucky = true;
            for(int j = 0; j < row; ++j){
                if(matrix[j][i] > matrix[maxRow][i]){
                    maxRow = j;
                }
            }
            for(int j = 0; j < col; ++j){
                if(matrix[maxRow][j] < matrix[maxRow][i]){
                    isLucky = false;
                    break;
                }
            }
            if(isLucky) res.push_back(matrix[maxRow][i]);
        }
        
        return res;
    }
};
```