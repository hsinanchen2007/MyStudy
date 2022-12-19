1. 从门的起点处开始搜索.
```
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int r = rooms.size();
        if(r <= 0){
            return;
        }
        int c = rooms[0].size();
        int d[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        vector<int> doors;
        queue<pair<int,int>> qu;
        
        for(int i = 0;i < r; ++i){
            for(int j = 0;j < c; ++j){
                if(rooms[i][j] == 0){
                    doors.push_back(i*c+j);
                }
            }
        }
        
        for(int i = 0;i < doors.size(); ++i){
            qu.push(make_pair(doors[i],0));
        }
        
        while(!qu.empty()){
            pair<int,int> curr = qu.front();
            qu.pop();
            
            for(int i = 0; i < 4; ++i){
                int x = curr.first/c + d[i][0];
                int y = curr.first%c + d[i][1];
                int dist = curr.second;
                
                if(x >= 0 && x < r && y >= 0 && y < c && rooms[x][y] > 0){
                    if(dist+1 < rooms[x][y]){
                        rooms[x][y] = dist + 1;
                        qu.push(make_pair(x*c+y,dist+1));
                    }
                }
            }
        }
        
    }
};
```