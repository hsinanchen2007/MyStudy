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
    int totalNQueens(int n) {
       col.resize(n,true);
        left_right.resize(2*n-1,true);
        right_left.resize(2*n-1,true);
        tmp.resize(n,string(n,'.'));
        nn = n;
        helper(0);
        
        return ret.size();//相比较与51，只是在这里改动了一下  返回了数量 
    }
};

```
