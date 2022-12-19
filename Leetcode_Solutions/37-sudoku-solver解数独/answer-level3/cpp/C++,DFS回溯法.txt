```
class Solution {
public:
    bool isValid(vector<vector<char>>& board,int i,int j,char c){
        //先判断行&列
        for(int k=0;k<9;k++){
            if(board[i][k]==c)return false;
            if(board[k][j]==c)return false;
        }
        for(int m=i/3*3;m<i/3*3+3;m++){//除3的作用是为了取整
            for(int n=j/3*3;n<j/3*3+3;n++){
                if(board[m][n]==c)return false;
            }
        }
        return true;

    } 
    bool dfs(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isValid(board,i,j,c)){
                            board[i][j]=c;
                            if(dfs(board))return true;//所有位置上面均有数字了，返回true
                            board[i][j]='.';//回溯
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board);
    }
};
```
