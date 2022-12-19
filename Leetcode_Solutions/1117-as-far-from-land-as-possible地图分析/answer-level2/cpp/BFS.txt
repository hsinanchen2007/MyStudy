```
typedef pair<int,int> pii;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int d[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        vector<vector<bool>> visit(r,vector<bool>(c,false));
        queue<pii> qu;
        
        for(int i = 0;i < r; ++i){
            for(int j = 0;j < c; ++j){
                if(grid[i][j] == 1){
                    qu.push(make_pair(i,j));
                }
            }
        }
        
        if(qu.size() == 0 || qu.size() == r*c){
            return -1;
        }
        
        int step = -1;
        while(!qu.empty()){
            step++;
            int level = qu.size();
            
            for(int i = 0;i < level; ++i){
                pii curr = qu.front();
                qu.pop();
                
                for(int j = 0;j < 4; ++j){
                    int x = curr.first + d[j][0];
                    int y = curr.second + d[j][1];
                    
                    if(x >= 0 && x < r && y >= 0 && y < c){
                        if(grid[x][y] == 0 && !visit[x][y]){
                            qu.push(make_pair(x,y));
                            visit[x][y] = true;
                        }
                    }
                }
            }
        }
        
        return step;
    }
};
```