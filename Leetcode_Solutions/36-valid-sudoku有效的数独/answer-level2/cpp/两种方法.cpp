用hash表的方法内存消耗较大

    vector<unordered_map<int,int>> cols(9),rows(9),blocks(9);
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                if(board[i][j]!='.'){
                    int bindex=(i/3)*3+j/3;
                    if(cols[i].count(board[i][j])||rows[j].count(board[i][j])||
                            blocks[bindex].count(board[i][j])){
                        return false;
                    }
                    cols[i][board[i][j]]=rows[j][board[i][j]]=blocks[bindex][board[i][j]]=1;
                }
            }
        }
        return true;

用数组存储出现数字个数的方法消耗内存较小

    bool isValidSudoku(vector<vector<char>>& board) {
        int cols[9][9]={0},rows[9][9]={0},blocks[9][9]={0};
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int data=board[i][j]-'0';
                    cols[i][data-1]++;
                    rows[j][data-1]++;
                    blocks[(i/3)*3+j/3][data-1]++;
                    if(cols[i][data-1]>1||rows[j][data-1]>1||blocks[(i/3)*3+j/3][data-1]>1){
                        return false;
                    }
                }
            }
        }
        return true;
    }