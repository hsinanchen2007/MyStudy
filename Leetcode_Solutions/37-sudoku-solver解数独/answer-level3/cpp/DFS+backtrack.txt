algorithm: 
```
0. using 3 2-nd arrays to record the state of sudoko. 
rows[10][10]; cols[10][10]; boxs[10][10]. 
  if rows[i][num] = true, means num has been used in ith-rows. 
1. record the current states of the board.
       rows , cols, boxes 
2. Fill the board recursively(DFS),  if failed, backtrack.
dfs:
 if solved: 
       return; 
 else if ( i >= 9 )
       solved = true;
       return; 
 if board[i][j] has number, search the next position:
    if ( j < 8 ) 
       dfs(i,j+1,board)
    else if ( j == 8 )
       dfs(i+1, 0, board)
    else if (solved)
       return; 

if board[i][j] is empty, fill this grid with number (try number from 1 to 9)
      if ( num could be put in grid (i,j)) 
              board[i][j] = num
              row[] = cols[] = boxs[] = true
              then search the next position:
              if ( j < 8 ) dfs (i,j+1, board)
              else if( j == 8) dfs (i+1,j,board)
              if (!solved) 
              backtrack:
                  rows[] = cols[] = boxs[] = false
                  board[i][j] = '.'
```

code 
```
class Solution {
public:
    bool solved=false;
    //using 3 2-nd arrays to record the state of sudoko. 
    bool row[10][10] = {false};
    bool col[10][10] = {false};
    bool box[10][10] = {false};

    void solveSudoku(vector<vector<char>>& board) {
        //1. record the current states of the board.
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')
                    continue;
                int box_index = 3*(i/3)+j/3;
                int num=board[i][j]-'0';
                row[i][num] = true; 
                col[j][num] = true; 
                box[box_index][num] = true;
            }
        }
        //Fill the board recursively.(Deep First Search)
        DFS(0,0,board);
    }

    //Fill the board recursively.(Deep First Search)
    void DFS(int i,int j,vector<vector<char>>& board){
        if(solved==true)
            return;
        if(i>=9) {
            solved=true;
            return;
        }
        //if board[i][j] is not empty, Fill the next position 
        if(board[i][j] != '.') {
            if(j<8) 
                DFS(i,j+1,board);
            else if(j==8)
                DFS(i+1,0,board);
            if(solved==true)
                return;
        }
        //if board[i][j] is empty, fill this position with a number(try to fill from 1 to 9)
        else {
            int box_index = 3*(i/3) + j/3;
            for(int num=1;num<=9;num++){
                // if can fill with num
                if( !row[i][num] && !col[j][num] && !box[box_index][num]) {   
                    
                    //fill the num
                    board[i][j] = num+'0'; 
                    
                    //update the states of the board
                    row[i][num] = true; 
                    col[j][num] = true; 
                    box[box_index][num] = true; 
                    

                    if(j<8)  
                        DFS(i,j+1,board);    
                    else if(j==8)
                        DFS(i+1,0,board);
                    
                    if(!solved) { // backtrack 
                        row[i][num] = false ; 
                        col[j][num] = false ; 
                        box[box_index][num] = false; 
                        board[i][j]='.';
                    }
                     
                }
            }
        }
    }
};

```