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
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    char c=board[i][j];
                    board[i][j]='.';
                    if(!isValid(board,i,j,c))return false;
                    board[i][j]=c;//还原，之前设置成.是为了方便后面的处理
                }
            }
        }
        return true;
    }
};
```
