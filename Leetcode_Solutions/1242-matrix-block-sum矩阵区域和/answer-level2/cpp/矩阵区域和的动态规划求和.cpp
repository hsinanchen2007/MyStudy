```cpp
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
       int row = mat.size(), col = mat[0].size();
       vector<vector<int>> answer(row, vector<int>(col, 0));  
       //前缀和, pre[i][j]表示(0, 0)到(i-1, j-1)的元素和
       vector<vector<int>> pre(row+1, vector<int>(col+1, 0)); //表示前缀和
       //求前缀和
       for(int i = 0;i < row; i++) {
           for(int j = 0; j < col; j++) {
               pre[i+1][j+1] = pre[i+1][j] + pre[i][j+1] - pre[i][j] + mat[i][j];
           }
       }
       //求目标矩阵
       for(int i = 0; i < row; i++) {
           for(int j = 0; j < col; j++) {
               int l = max(j-K, 0); 
               int t = max(i-K, 0);
               int r = min(j+K, col-1);
               int b = min(i+K, row-1);
               answer[i][j] = pre[b+1][r+1] - pre[b+1][l+1-1] - pre[t+1-1][r+1] + pre[t+1-1][l+1-1];
           }
       }
       return answer;
    }
    
};
```
