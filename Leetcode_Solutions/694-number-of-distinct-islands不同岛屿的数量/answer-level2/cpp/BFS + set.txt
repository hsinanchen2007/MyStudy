1. 先将矩阵中的每个连通分量求出来。
2. 然后进行整型，主要是将连通分量全部往左上角进行位移。
3. 通过set来统计岛屿的数量。

```
class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int d[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        vector<vector<pair<int,int>>> islands;
        vector<vector<bool>> visit(r,vector<bool>(c,false));
        queue<pair<int,int>> qu;
        
        for(int i = 0;i < r; ++i){
            for(int j = 0;j < c; ++j){
                if(!visit[i][j]&&grid[i][j]){
                    visit[i][j] = true;
                    qu.push(make_pair(i,j));
                    vector<pair<int,int>> land;
                    
                    while(!qu.empty()){
                        pair<int,int> curr = qu.front();
                        int x = curr.first;
                        int y = curr.second;
                        land.push_back(curr);
                        qu.pop();
                        
                        for(int k = 0;k < 4; ++k){
                            int x1 = x + d[k][0];
                            int y1 = y + d[k][1];
                            if(x1 >= 0 && x1 < r &&
                               y1 >= 0 && y1 < c &&
                               grid[x1][y1] && !visit[x1][y1]){
                                visit[x1][y1] = true;
                                qu.push(make_pair(x1,y1));
                            }
                        }
                    }
                    islands.push_back(land);
                }
            }
        }
        
        for(int i = 0;i < islands.size(); ++i){
            int top = islands[i][0].first;
            int left = islands[i][0].second;
            for(int j = 0;j < islands[i].size(); ++j){
                top = min(top,islands[i][j].first);
                left = min(left,islands[i][j].second);
            }
            for(int j = 0;j < islands[i].size(); ++j){
                islands[i][j].first -= top;
                islands[i][j].second -= left;
            }
        }
        
        set<vector<pair<int,int>>> count;
        for(int i = 0;i < islands.size(); ++i){
            count.insert(islands[i]);
        }
        
        return count.size();
    }
};
```