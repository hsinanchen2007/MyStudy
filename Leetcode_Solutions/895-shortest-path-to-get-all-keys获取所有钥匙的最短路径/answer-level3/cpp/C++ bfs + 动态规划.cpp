难点在于状态转换
visit[x][y][state];
```
class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int sx = 0;
        int sy = 0;
        int r = grid.size();
        int c = grid[0].size();
        int n = 0;
        
        /*find key and lock*/
        for(int i = 0;i < r; ++i){
            for(int j = 0;j < c; ++j){
                if(grid[i][j] >= 'a' && grid[i][j] <= 'z'){
                   n++;
                }
                if(grid[i][j] == '@'){
                    sx = i;
                    sy = j;
                }
            }
        }
        
        int mask = (1<<n)-1;
        int visit[30][30][128];
        int step = -1;
        int d[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<pair<int,int>,int>> qu;
        
        /*initial*/
        memset(visit,0,sizeof(visit));
        qu.push(make_pair(make_pair(sx,sy),0));
        visit[sx][sy][0] = true;
                
        /*get*/
        while(!qu.empty()){
            int mx = qu.size();
            step++;
            
            for(int i = 0;i < mx; ++i){
                int x = qu.front().first.first;
                int y = qu.front().first.second;
                int state = qu.front().second;
                qu.pop();
                
                if(state == mask){
                    return step;
                }
                
                for(int j = 0;j < 4; ++j){
                    int x1 = x + d[j][0];
                    int y1 = y + d[j][1];
                    if(x1 >= 0 && y1 >= 0 && x1 < r && y1 < c){
                        /*wall*/
                        if(grid[x1][y1] == '#'){
                            continue;
                        }else if(grid[x1][y1] >= 'a' && grid[x1][y1] <= 'f'){
                            /*key*/
                            int currState = state|(1<<(grid[x1][y1]-'a'));
                            if(!visit[x1][y1][currState]){
                                visit[x1][y1][currState] = 1;
                                qu.push(make_pair(make_pair(x1,y1),currState));
                            }
                        }else if(grid[x1][y1] >= 'A' && grid[x1][y1] <= 'F'){
                            /*lock*/
                            if(!visit[x1][y1][state]){
                                if(state&(1<<(grid[x1][y1]-'A'))){
                                    visit[x1][y1][state] = 1;
                                    qu.push(make_pair(make_pair(x1,y1),state));
                                }
                            }
                        }else if(grid[x1][y1] == '.'||grid[x1][y1] == '@'){
                            /*room*/
                            if(!visit[x1][y1][state]){
                                visit[x1][y1][state] = 1;
                                qu.push(make_pair(make_pair(x1,y1),state));
                            }
                        }
                        
                    }
                }
                
            }
        }
        
        return -1;
    }
};
```
