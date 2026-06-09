```c++
typedef pair<int,int> pii;

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        queue<pii> qu;
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visit(row,vector<bool>(col,false));
        
        int next[4][7];
        int d[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
        memset(next,-1,sizeof(next));
        /*left*/
        next[0][1] = 0;
        next[0][4] = 3;
        next[0][6] = 2;
        /*right*/
        next[1][1] = 1;
        next[1][3] = 3;
        next[1][5] = 2;
        /*up*/
        next[2][2] = 2;
        next[2][3] = 0;
        next[2][4] = 1;
        /*down*/
        next[3][2] = 3;
        next[3][5] = 0;
        next[3][6] = 1;
      
        if(grid[0][0] == 1){
            qu.push(make_pair(1,0));//go  right
        }else if(grid[0][0] == 2){
            qu.push(make_pair(3,0));//go  down
        }else if(grid[0][0] == 3){
            qu.push(make_pair(1,0));//go right
        }else if(grid[0][0] == 4){
            qu.push(make_pair(0,0));//go left
            qu.push(make_pair(2,0));//go up
        }else if(grid[0][0] == 5){
            qu.push(make_pair(1,0));//go right
        }else if(grid[0][0] == 6){
            qu.push(make_pair(3,0));//go down
        }
        visit[0][0] = true;
        while(!qu.empty()){
            int cd = qu.front().first;
            int cx = qu.front().second/col;
            int cy = qu.front().second%col;
            qu.pop();
            if(next[cd][grid[cx][cy]] == -1) continue;
            if(cx == row-1 && cy == col-1) return true; 
            
            int nd = next[cd][grid[cx][cy]];
            int nx = cx + d[nd][0];
            int ny = cy + d[nd][1];
            if(nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
            if(visit[nx][ny]) continue;
            qu.push(make_pair(nd,nx*col+ny));
            visit[nx][ny] = true;
        }
        
        return false;
    }
};
```