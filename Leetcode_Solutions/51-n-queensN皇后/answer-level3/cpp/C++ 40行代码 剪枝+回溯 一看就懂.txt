8皇后问题是经典的算法问题，看起来很难，实际上思想很容易理解。而理解了思想，写算法就不至于“修补答案”。本题我用的方法是：剪枝+回溯。看到剪枝，就会想到约束编程；看到回溯，大概率会用递归。代码就是下面的样子。有注释辅助理解。

```
class Solution {
public:
    vector<vector<string>> ret;//最终结果
    vector<string> tmp;//临时存储可能的一个解
    vector<bool> col;//列
    vector<bool> left_right;//从左上到右下的对角线
    vector<bool> right_left;//从右上到左下的对角线
    int nn = 0;
    
    void helper(int row_n){
        if(row_n == nn){
            ret.push_back(tmp);
            return;
        }
        
        for(int col_n=0;col_n<nn;col_n++){
            int left = (col_n - row_n) + nn - 1;
            int right = col_n + row_n;
            if(col[col_n] && left_right[left] && right_left[right]){//剪枝
                tmp[row_n][col_n] = 'Q';
                col[col_n] = false;
                left_right[left] =false;
                right_left[right] = false;
                
                helper(row_n + 1);
                
                tmp[row_n][col_n] = '.';//回溯
                col[col_n] = true;
                left_right[left] =true;
                right_left[right] = true;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        col.resize(n,true);
        left_right.resize(2*n-1,true);
        right_left.resize(2*n-1,true);
        tmp.resize(n,string(n,'.'));
        nn = n;
        helper(0);
        
        return ret;
    }
};
```
