按每行的选择进行搜索及回溯判断
vector<int> pos(n, -1)； 存放每一行的选择（列号）
每递增一行，判断合法性
搜索填充至最后一行，则输出

合法性判别： （row，col）
1）判断col是否与已经存于pos表之内的列号冲突，只需要判断比row小的行，因为是从第一行递增来的
2）判断（row，col）是否与已经存在的皇后点对角冲突，对角冲突2点，行号差和列号差相等 

```
class Solution {
public:
    bool isQueen(vector<int>& pos, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (col == pos[i] || (abs(row-i)==abs(col-pos[i]))) return false;
        }
        return true;
    }
    
    void dfs(vector<vector<string>>& ans,vector<int>& pos, int row, int n){
        if (row == n){
            vector<string> out(n,string(n,'.'));
            for (int i=0;i<n;++i)
                out[i][pos[i]] = 'Q';
            ans.emplace_back(out);
            return;
        }
        for (int col=0;col<n;++col){
            if (isQueen(pos,row,col)){
                pos[row] = col;
                dfs(ans,pos,row+1,n);
                pos[row] = -1;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> pos(n, -1);
        dfs(ans,pos,0,n);
        return ans;
    }
};
```
