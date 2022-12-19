```
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        if(!board.size()) return 0;
        int row = board.size();
        int col = board[0].size();
        int dir_x[4] = {1,-1,0,0};
        int dir_y[4] = {0,0,1,-1};
        pair<int,int> pos;
        int ans = 0;
        for(int r=0; r<row; ++r){  //找车
            for(int c=0; c<col; ++c){
                if(board[r][c] == 'R'){
                    pos = make_pair(r,c);
                    break;
                }
            }
        }
        for(int i=0; i<4; ++i){
            int new_x = pos.first;  //找完一个方向回到车的初始位置，换方向找。
            int new_y = pos.second;
            while(new_x+dir_x[i]<row && new_x+dir_x[i]>=0 && new_y+dir_y[i]<col && new_y+dir_y[i]>=0){ //判边缘
                new_x += dir_x[i];
                new_y += dir_y[i];
                if(board[new_x][new_y] == 'p'){  //找卒
                    ans++;
                    break;
                }
                if(board[new_x][new_y] == 'B') break;   //找象             
            }
        }
        return ans;
    }
};
```
