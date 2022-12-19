### 解题思路
回溯递归法解决八皇后问题,不能在同一行/列/斜线，一共有92种情况,替换8为n即可；
用res存储递归边界得出的每种情况，用chess和visit标记整个棋盘以及每列是否被访问。

### 代码

```cpp
class Solution {
    int n;
    int cnt = 0;
public:
    bool XieXian(vector<vector<bool>> chess, int row, int col){
        for(int i=0; i<n; i++){
            int dis = row-i;
            if(col+dis>=0 && col+dis<n){ 
                if(chess[i][col+dis]){
                    return false;
                }
            }
            if(col-dis>=0 && col-dis<n){ 
                if(chess[i][col-dis]){
                    return false;
                }
            }
        }
        return true;
    }

    void dfs(vector<vector<string>> & res, vector<vector<bool>>& chess, vector<bool>& visit, int i, int depth){  //i=column, depth=row
        if(depth == n){  //递归边界,一种情况结束
            cnt ++;
            vector<string> plan(n, "");
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    plan[i] += chess[i][j] ? 'Q' : '.';
                }
            }
            res.push_back(plan);
            return;
        }
        else{  
            for(int j=0; j<n; j++){
                if(!visit[j] && XieXian(chess, depth, j)){
                    visit[j] = true;
                    chess[depth][j] = true;   //标记已访问
                    dfs(res, chess, visit, j, depth+1);
                    visit[j] = false;   //回溯
                    chess[depth][j] = false;  //当 depth+1=n 时 return; 此时递归栈中 depth=7
                }
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<bool>> chess(n, vector<bool>(n,false));
        vector<bool> visit(n, false); //n列，标记是否访问
        vector<vector<string>>  res( cnt, vector<string>(n) );
        this->n = n;
        for(int i=0; i<n; i++){  //从第一行中八列中选择一列开始
            if(!visit[i]){
                visit[i] = true;
                chess[0][i] = true;
                dfs(res, chess, visit, i, 1);   //递归深度，从第2行开始dfs
                visit[i] = false;
                chess[0][i] = false;  //必须回溯
            }
        }
        return res;
    }
};





```