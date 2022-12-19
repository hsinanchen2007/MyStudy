这个题比较坑爹，主要是比较形状。

```
class Solution {
public:
    int find(vector<int> & f, int x){
        while(x != f[x]){
            x = f[x];
        }
        return x;
    }
    
    bool uni(vector<int> & f,int x,int y){
        int x1 = find(f,x);
        int y1 = find(f,y);
        f[x1] = y1;
        return true;
    }
    
    bool isSame(vector<pair<int,int>> & a,vector<pair<int,int>> &b){
        for(int i = 0;i < a.size(); ++i){
            if(a[i].first != b[i].first || 
               a[i].second != b[i].second){
                return false;
            }
        }
        
        return true;
    }
    
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
        
        int n = islands.size();        
        vector<int> f(n,0);
        set<int> count;
        
        for(int i = 0;i < n; ++i){
            f[i] = i;
        }
                
        for(int i = 0;i < islands.size(); ++i){
            for(int j = i+1;j < islands.size(); ++j){
                if(islands[i].size() == islands[j].size() && 
                   isSame(islands[i],islands[j])){
                    uni(f,i,j);
                }
            }
        }
        
        for(int i = 0; i < n; ++i){
            count.insert(find(f,i));
        }
        
        return count.size();
    }
};
```