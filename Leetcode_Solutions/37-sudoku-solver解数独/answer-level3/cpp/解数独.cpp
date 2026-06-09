    void BackTrack(vector<vector<char>>& board,vector<vector<int>>& cols,
            vector<vector<int>>& rows,vector<vector<int>>& blocks,int i,int j,bool& done){
        if(done==true){
            return;
        }
        if(i>=9){
            done=true;
            return;
        }
        int k,m;
        if(j<8){
            m=j+1;
            k=i;
        }
        else{
            m=0;
            k=i+1;
        }
        if(board[i][j]!='.'){
            BackTrack(board,cols,rows,blocks,k,m,done);
        }
        else{
            for(int data=0;data<9;data++){
                if(cols[i][data]==0&&rows[j][data]==0&&blocks[(i/3)*3+j/3][data]==0){
                    cols[i][data]=rows[j][data]=blocks[(i/3)*3+j/3][data]=1;
                    board[i][j]=(char)(data+'0'+1);
                    BackTrack(board,cols,rows,blocks,k,m,done);
                    if(done==false){
                        cols[i][data]=rows[j][data]=blocks[(i/3)*3+j/3][data]=0;
                        board[i][j]='.';
                    }
                }
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> cols(9,vector<int>(9,0)),rows(9,vector<int>(9,0)),blocks(9,vector<int>(9,0));
        bool done=false;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int data=board[i][j]-'0';
                    cols[i][data-1]=rows[j][data-1]=blocks[(i/3)*3+j/3][data-1]=1;
                }
            }
        }
        BackTrack(board,cols,rows,blocks,0,0,done);
    }   