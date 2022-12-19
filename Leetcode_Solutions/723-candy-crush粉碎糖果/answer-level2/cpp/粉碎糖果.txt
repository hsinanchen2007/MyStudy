```
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int m = board.size(); if(m==0) return board;
        int n = board[0].size(); if(n==0) return board;
        while(1){
            // 统计每行大于3个的位置，并用负数标记
            for(int i=0; i<m; i++){
                int count = 1;
                int flag = abs(board[i][0]);
                for(int j=1; j<n; j++){
                    if(abs(board[i][j])==flag){
                        count++;
                    }else{
                        if(count>=3){ 
                            for(; count>0; count--) board[i][j-count] = -abs(board[i][j-count]);
                        }
                        count = 1;
                        flag = abs(board[i][j]);
                    }
                }
                if(count>=3){
                    for(; count>0; count--) board[i][n-count] = -abs(board[i][n-count]);
                }
            }
            // 统计每列大于3个的位置，并用负数标记
            for(int i=0; i<n; i++){
                int count = 1;
                int flag = abs(board[0][i]);
                for(int j=1; j<m; j++){
                    if(abs(board[j][i])==flag){
                        count++;
                    }else{
                        if(count>=3){ 
                            for(; count>0; count--) board[j-count][i] = -abs(board[j-count][i]);
                        }
                        count = 1;
                        flag = abs(board[j][i]);
                    }
                }
                if(count>=3){
                    for(; count>0; count--) board[m-count][i] = -abs(board[m-count][i]);
                }
            }
            // 将负数替换为0
            bool change = false;
            for(int i=0; i<m; i++)
                for(int j=0; j<n; j++)
                    if(board[i][j]<0){board[i][j]=0; change=true;}
            if(change==false) break;
            // 下移
            for(int j=0; j<n; j++){
                int num_removed = 0;
                for(int i=m-1; i>=0; i--){
                    if(board[i][j]==0){
                        num_removed++;
                    }else board[i+num_removed][j] = board[i][j];
                }
                for(int i=0; i<num_removed; i++) board[i][j]=0;
            }
        }
        return board;
    }
```