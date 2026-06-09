```
// 用了3个辅助占用数组，左斜，右斜，列
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> tmp(n, string (n,'.'));
        vector<vector<string>> res;
        vector<int> occupy_col(n, 0);
        vector<int> occupy_cross_left(2*n, 0);
        vector<int> occupy_cross_right(2*n, 0);
        solveNQueensCore(res, tmp, 0, occupy_col, occupy_cross_left, occupy_cross_right, n);
        return res;
    }
    
    void solveNQueensCore(vector<vector<string>> &res, vector<string> &tmp, int cur, 
                          vector<int> &occupy_col, vector<int> &occupy_cross_left, vector<int> &occupy_cross_right, const int &n){
        if(cur==n){
            res.push_back(tmp);
            return;
        }
        for(int i = 0; i<n; i++){
            if(!occupy_col[i] && !occupy_cross_left[n-cur+i] && !occupy_cross_right[cur+i]){
                tmp[cur][i] = 'Q';
                occupy_col[i] = 1;
                occupy_cross_left[n-cur+i]+=1;
                occupy_cross_right[cur+i]+=1;
                solveNQueensCore(res, tmp, cur+1, occupy_col, occupy_cross_left, occupy_cross_right, n);
                tmp[cur][i] = '.';
                occupy_col[i] = 0;
                occupy_cross_left[n-cur+i]-=1;
                occupy_cross_right[cur+i]-=1;
            }
        }
    }
};
```
