```
class Solution {
public:
    vector<int> pondSizes(vector<vector<int>>& land) 
    {
        vector<int> res;
        if(land.size() == 0) return res;
        for(int i = 0;i < land.size();i++){
            for(int j = 0;j < land[0].size();j++){
                if(land[i][j] == 0){
                    res.push_back(dfs(i,j,land));
                } 
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
    int dfs(int x,int y,vector<vector<int>>& land){
        if(x < 0 || y < 0 || x == land.size() || y == land[0].size()) return 0;
        if(land[x][y]) return 0;
        land[x][y] = 1;
        return 1+dfs(x+1,y,land)+dfs(x-1,y,land)+dfs(x,y+1,land)+dfs(x,y-1,land)+dfs(x+1,y+1,land)+dfs(x+1,y-1,land)+dfs(x-1,y-1,land)+dfs(x-1,y+1,land);
    }
};
```
