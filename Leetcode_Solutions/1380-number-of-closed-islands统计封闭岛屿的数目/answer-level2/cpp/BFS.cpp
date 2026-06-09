```c++
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int res = 0;
        int d[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        vector<vector<bool>> visit(r,vector<bool>(c,false));
        
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                if(!visit[i][j] && grid[i][j] == 0){
                    queue<pair<int,int>> qu;
                    visit[i][j] = true;
                    bool isClose = true;
                    qu.push(make_pair(i,j));
                    
                    while(!qu.empty()){
                        int x = qu.front().first;
                        int y = qu.front().second;
                        qu.pop();
                        if(x == 0 || x == r-1 || \
                           y == 0 || y == c-1){
                            isClose = false;
                        }
                        
                        for(int k = 0; k < 4; ++k){
                            int x1 = x + d[k][0];
                            int y1 = y + d[k][1];
                            if(x1 >= 0 && x1 < r && y1 >= 0 && y1 < c &&\
                               grid[x1][y1] == 0 && !visit[x1][y1]){
                                visit[x1][y1] = true;
                                qu.push(make_pair(x1,y1));
                            }
                        }
                    }
                    
                    if(isClose){
                        res++;
                    }
                }
            }
        }
        
        return res;
    }
};
```