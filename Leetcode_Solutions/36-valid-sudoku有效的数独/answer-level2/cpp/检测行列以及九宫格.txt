```c++
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool flag1=1,flag2=1,flag3=1;
        for(int i=0;i<9;i++){
            int v=0,u=0;
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int a = board[i][j] - '0';
                    if((1<<a) & v){ //检查同行元素
                        flag1=0;
                    }else{
                        v|=1<<a;
                    }
                }
                if(board[j][i]!='.'){
                    int a = board[j][i] - '0'; //检查同列元素
                    if((1<<a)&u){
                        flag2=0;
                    }else {
                        u|=1<<a;
                    }
                }
            }
            if(i%3==0){
                for(int j=0;j<9;j+=3){
                    int w=0;
                    for(int k=0;k<3;k++){
                        for(int q=0;q<3;q++){
                            if(board[i+k][j+q]=='.')continue;
                            int a = board[i+k][j+q] - '0'; //检查九宫格
                            if((1<<a)&w){
                                flag3=0;
                                break;
                            }else {
                                w|=1<<a;
                            }
                        }
                    }
                }
            }
        }
        return flag1 & flag2 & flag3;
    }
};
```