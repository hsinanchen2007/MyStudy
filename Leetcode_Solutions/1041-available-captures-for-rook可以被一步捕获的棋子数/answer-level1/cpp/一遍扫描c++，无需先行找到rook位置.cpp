仅在一遍扫描之内完成任务，无需先行扫描确定rook位置。
大致思路：分遇到rook前后两种情况，采用不同的记录方案。
使用了unordered_set便于快速寻找和去除重复。
双100%通过。
```c++
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        bool rook=false,right=false,left=false,up=false,down=false;
        int capture=0,row=-1,column=-1;//row，column是rook的位置
        unordered_set<int> columns,rows;
        for (int i=0;i<board.size();++i) {
            for (int j=0;j<board[0].size();++j) {
                if(!rook){//遇到rook之前
                    if(board[i][j]=='B'){//清理不可吃的位置
                        columns.erase(j);
                        rows.erase(i);
                    }
                    if(!up&&!left&&board[i][j]=='p'){//记录可能被吃的位置
                        columns.insert(j);     
                        rows.insert(i); 
                    }else if(board[i][j]=='R'){
                        row=i;
                        column=j;
                        rook=true;//标记遇到rook
                        if(columns.find(column)!=columns.end()){
                            capture++;
                            up=true;//标记已经吃过该方向
                        }
                        if(rows.find(row)!=rows.end()){
                            capture++;
                            left=true;//标记已经吃过该方向
                        }
                    }
                }else{//遇到rook之后
                    if(board[i][j]=='B'){
                        // 遇到白色biship，之后该行，列的pawn无法作为被吃对象，
                        if(i==row) right=true;//该方向再无法被吃
                        if(j==column) down=true;//该方向再无法被吃
                    }
                    if(board[i][j]=='p'){// 遇到pawn
                        if(!right&&i==row){//右边尚未吃过棋子，处于可吃状态
                            capture++;
                            right=true;//标记已经吃过该方向
                        }
                        if(!down&&j==column){//下边尚未吃过棋子，处于可吃状态
                            down=true;//标记已经吃过该方向
                            capture++;
                        }
                    }
                }
            }
        }
        return capture;
    }
};
```
