class Solution {
public:
    vector<vector<char>> ans;
    bool check(vector<vector<char>>& board, int x, int y, int num){//检查行、列、格
        bool can=true;
        int gridx=x/3;//确定是哪个九宫格
        int gridy=y/3;
        for(int i=0;i<9;i++){
            if(board[x][i]-'0'==num||board[i][y]-'0'==num||board[gridx*3+i/3][gridy*3+i%3]-'0'==num){
                can=false;
                break;
            }
        }
        return can;
    }
    void nextstep(vector<vector<char>>& board, int index){//index表示试探到第几个点
        int x=index/9;//利用index获得行号和列号
        int y=index%9;
        if(index>80){
            ans=board;
            return;
        }
        else{
            if(board[x][y]=='.'){
                for(int num=1;num<=9;num++){
                    if(check(board,x,y,num)){
                        board[x][y]=(char(num+'0'));
                        nextstep(board, (index+1));//递归
                        board[x][y]='.';//回溯
                    }
                }
            }
            else{
                nextstep(board, index+1);
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        nextstep(board,0);
        board=ans;
    }
};