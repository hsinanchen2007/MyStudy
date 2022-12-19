
先遍历列，再遍历行。

```c++ []
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int rows = A.size();
        int cols = A[0].size();
        vector<vector<int>> B(cols, vector<int>(rows, 0));
        for(int i  = 0;i < cols; ++i){
            for(int j = 0;j < rows; ++j){
                B[i][j] = A[j][i];
            }  
        }
        return B;
    } 
};
```