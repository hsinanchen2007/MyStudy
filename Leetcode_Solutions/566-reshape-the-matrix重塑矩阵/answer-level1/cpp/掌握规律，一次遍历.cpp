

```
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        
        int row = nums.size();//原矩阵的行数
        int column  = nums[0].size();//原矩阵的列数
        
        if(row*column != r*c ||(row==r && column==c))//如果不可行或新矩阵和原矩阵一致则输出原始矩阵
            return nums;
        
        
        
        
        vector<vector<int>> output(r,vector<int>(c));
        
        for(int i=0; i<row*column; i++){
            
            int old_row = i/column;//旧行数
            int old_col = i%column;//旧列数
            int new_row = i/c;//新行数
            int new_col = i%c;//新列数
            
            output[new_row][new_col] = nums[old_row][old_col];
        }


        
        return output;
        
    }
};
```
